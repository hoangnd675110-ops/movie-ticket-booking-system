#pragma once
#include <vector>
#include <memory>
#include <string>

class Person;
class Show;
class Theater;
class Ticket;
class NotificationService;

class BookingSystem {
private:
    std::vector<std::unique_ptr<Person>> m_persons;
    std::vector<std::unique_ptr<Show>> m_shows;
    std::vector<std::unique_ptr<Theater>> m_theaters;
    std::vector<std::unique_ptr<Ticket>> m_tickets;
    std::unique_ptr<NotificationService> m_notifier;
    int m_nextTicketId;

public:
    BookingSystem();
    ~BookingSystem();

    void setNotifier(std::unique_ptr<NotificationService> notifier);

    void addPerson(std::unique_ptr<Person> person);
    void addShow(std::unique_ptr<Show> show);
    void addTheater(std::unique_ptr<Theater> theater);

    void initializeDefaultData();

    void displayAllPersons() const;
    void displayAllShows() const;
    void displayAllTheaters() const;
    void displayTheaterSeats(int theaterIndex) const;
    void displayAllTickets() const;

    bool bookTicket(int showIndex, int theaterIndex, int row, int col,
                    const std::string& customerName, const std::string& ticketType,
                    int groupSize = 1);
    bool cancelTicket(int ticketId);

    int getPersonCount() const;
    int getShowCount() const;
    int getTheaterCount() const;
    int getTicketCount() const;

    const Show* getShow(int index) const;
    const Theater* getTheater(int index) const;
};
