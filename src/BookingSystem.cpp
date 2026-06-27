#include "BookingSystem.h"
#include "Customer.h"
#include "Admin.h"
#include "Movie.h"
#include "Concert.h"
#include "RegularSeat.h"
#include "VIPSeat.h"
#include "Theater.h"
#include "StandardTicket.h"
#include "GroupTicket.h"
#include "ConsoleNotification.h"
#include "ConsoleUtils.h"
#include <iostream>
#include <iomanip>
#include <sstream>

BookingSystem::BookingSystem()
    : m_notifier(std::make_unique<ConsoleNotification>()), m_nextTicketId(1) {}

BookingSystem::~BookingSystem() = default;

void BookingSystem::setNotifier(std::unique_ptr<NotificationService> notifier) {
    m_notifier = std::move(notifier);
}

void BookingSystem::addPerson(std::unique_ptr<Person> person) {
    m_persons.push_back(std::move(person));
}

void BookingSystem::addShow(std::unique_ptr<Show> show) {
    m_shows.push_back(std::move(show));
}

void BookingSystem::addTheater(std::unique_ptr<Theater> theater) {
    m_theaters.push_back(std::move(theater));
}

void BookingSystem::initializeDefaultData() {
    addPerson(std::make_unique<Customer>("Alice Johnson", "alice@email.com", "555-0101"));
    addPerson(std::make_unique<Customer>("Bob Smith", "bob@email.com", "555-0102"));
    addPerson(std::make_unique<Admin>("Charlie Admin", "charlie@cinema.com", "555-0001", "STAFF001"));

    addShow(std::make_unique<Movie>(1, "The Dark Knight", 152, 12.50, "Action"));
    addShow(std::make_unique<Movie>(2, "Inception", 148, 12.50, "Sci-Fi"));
    addShow(std::make_unique<Movie>(3, "Interstellar", 169, 14.00, "Sci-Fi"));
    addShow(std::make_unique<Concert>(4, "Rock Night", 180, 25.00, "The Rockers"));
    addShow(std::make_unique<Concert>(5, "Jazz Evening", 120, 20.00, "Blue Note Trio"));

    addTheater(std::make_unique<Theater>(1, "Screen 1", 5, 8));
    addTheater(std::make_unique<Theater>(2, "Screen 2", 4, 6));
    addTheater(std::make_unique<Theater>(3, "Screen 3", 6, 10));
}

void BookingSystem::displayAllPersons() const {
    if (m_persons.empty()) {
        printCentered("No persons registered.");
        return;
    }
    for (size_t i = 0; i < m_persons.size(); ++i) {
        std::ostringstream oss;
        std::streambuf* old = std::cout.rdbuf(oss.rdbuf());
        std::cout << "[" << i << "] ";
        m_persons[i]->displayInfo();
        std::cout.rdbuf(old);
        printCentered(oss.str());
    }
}

void BookingSystem::displayAllShows() const {
    if (m_shows.empty()) {
        printCentered("No shows available.");
        return;
    }
    for (size_t i = 0; i < m_shows.size(); ++i) {
        std::ostringstream oss;
        std::streambuf* old = std::cout.rdbuf(oss.rdbuf());
        std::cout << "[" << i << "] ";
        m_shows[i]->display();
        std::cout.rdbuf(old);
        printCentered(oss.str());
    }
}

void BookingSystem::displayAllTheaters() const {
    if (m_theaters.empty()) {
        printCentered("No theaters available.");
        return;
    }
    for (size_t i = 0; i < m_theaters.size(); ++i) {
        std::ostringstream oss;
        oss << "[" << i << "] " << m_theaters[i]->getName()
            << " (" << m_theaters[i]->getRows() << "x"
            << m_theaters[i]->getCols() << " = "
            << m_theaters[i]->getTotalSeats() << " seats, "
            << m_theaters[i]->getAvailableSeats() << " available)";
        printCentered(oss.str());
    }
}

void BookingSystem::displayTheaterSeats(int theaterIndex) const {
    if (theaterIndex < 0 || theaterIndex >= static_cast<int>(m_theaters.size())) {
        printCentered("Invalid theater index.");
        return;
    }
    std::ostringstream oss;
    std::streambuf* old = std::cout.rdbuf(oss.rdbuf());
    m_theaters[theaterIndex]->displaySeats();
    std::cout.rdbuf(old);
    std::string line;
    std::istringstream iss(oss.str());
    while (std::getline(iss, line))
        printCentered(line);
}

void BookingSystem::displayAllTickets() const {
    if (m_tickets.empty()) {
        printCentered("No tickets booked.");
        return;
    }
    for (const auto& t : m_tickets) {
        std::ostringstream oss;
        std::streambuf* old = std::cout.rdbuf(oss.rdbuf());
        t->display();
        std::cout << "----------------";
        std::cout.rdbuf(old);
        std::string line;
        std::istringstream iss(oss.str());
        while (std::getline(iss, line))
            printCentered(line);
    }
}

bool BookingSystem::bookTicket(int showIndex, int theaterIndex, int row, int col,
                                const std::string& customerName,
                                const std::string& ticketType, int groupSize) {
    if (showIndex < 0 || showIndex >= static_cast<int>(m_shows.size()))
        return false;
    if (theaterIndex < 0 || theaterIndex >= static_cast<int>(m_theaters.size()))
        return false;

    Theater* theater = m_theaters[theaterIndex].get();
    Seat* seat = theater->getSeat(row, col);
    if (!seat || !seat->isAvailable())
        return false;

    theater->bookSeat(row, col, customerName);

    std::unique_ptr<Ticket> ticket;
    if (ticketType == "group") {
        ticket = std::make_unique<GroupTicket>(
            m_nextTicketId++, m_shows[showIndex].get(), seat, customerName, groupSize);
    } else {
        ticket = std::make_unique<StandardTicket>(
            m_nextTicketId++, m_shows[showIndex].get(), seat, customerName);
    }

    double price = ticket->calculatePrice();
    m_tickets.push_back(std::move(ticket));

    std::string msg = "Booking confirmed for " + customerName
                    + " | Show: " + m_shows[showIndex]->getTitle()
                    + " | Seat: " + std::string(1, 'A' + row) + std::to_string(col + 1)
                    + " | Total: $" + std::to_string(price);
    m_notifier->send(customerName + " <" + customerName + "@email.com>", msg);

    return true;
}

bool BookingSystem::cancelTicket(int ticketId) {
    for (auto it = m_tickets.begin(); it != m_tickets.end(); ++it) {
        if ((*it)->getId() == ticketId) {
            m_tickets.erase(it);
            return true;
        }
    }
    return false;
}

int BookingSystem::getPersonCount() const { return static_cast<int>(m_persons.size()); }
int BookingSystem::getShowCount() const { return static_cast<int>(m_shows.size()); }
int BookingSystem::getTheaterCount() const { return static_cast<int>(m_theaters.size()); }
int BookingSystem::getTicketCount() const { return static_cast<int>(m_tickets.size()); }

const Show* BookingSystem::getShow(int index) const {
    if (index < 0 || index >= static_cast<int>(m_shows.size()))
        return nullptr;
    return m_shows[index].get();
}

const Theater* BookingSystem::getTheater(int index) const {
    if (index < 0 || index >= static_cast<int>(m_theaters.size()))
        return nullptr;
    return m_theaters[index].get();
}
