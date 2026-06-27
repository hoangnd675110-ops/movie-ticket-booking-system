#include "Ticket.h"
#include "Show.h"
#include "Seat.h"
#include <iostream>
#include <iomanip>

Ticket::Ticket(int id, const Show* show, const Seat* seat, const std::string& customerName)
    : m_id(id), m_show(show), m_seat(seat), m_customerName(customerName) {}

int Ticket::getId() const { return m_id; }
std::string Ticket::getCustomerName() const { return m_customerName; }
std::string Ticket::getShowTitle() const { return m_show->getTitle(); }
std::string Ticket::getSeatLabel() const { return m_seat->getLabel(); }
std::string Ticket::getSeatPosition() const {
    char rowChar = static_cast<char>('A' + m_seat->getRow());
    return std::string(1, rowChar) + std::to_string(m_seat->getCol() + 1);
}

double Ticket::calculatePrice() const {
    return m_seat->getFinalPrice(m_show->getPrice());
}

std::string Ticket::getType() const { return "Standard"; }

void Ticket::display() const {
    std::cout << "Ticket #" << m_id << " (" << getType() << ")\n";
    std::cout << "  Customer: " << m_customerName << "\n";
    std::cout << "  Show:     " << m_show->getTitle()
              << " (" << m_show->getType() << ")\n";
    std::cout << "  Seat:     " << getSeatPosition()
              << " (" << m_seat->getLabel() << ")\n";
    std::cout << "  Price:    $" << std::fixed << std::setprecision(2)
              << calculatePrice() << "\n";
}
