#include "GroupTicket.h"
#include "Show.h"
#include "Seat.h"
#include <iostream>
#include <iomanip>

GroupTicket::GroupTicket(int id, const Show* show, const Seat* seat,
                         const std::string& customerName, int groupSize)
    : Ticket(id, show, seat, customerName), m_groupSize(groupSize) {}

int GroupTicket::getGroupSize() const { return m_groupSize; }

double GroupTicket::calculatePrice() const {
    double base = m_seat->getFinalPrice(m_show->getPrice());
    return base * m_groupSize * 0.85;
}

std::string GroupTicket::getType() const { return "Group"; }

void GroupTicket::display() const {
    std::cout << "Ticket #" << m_id << " (" << getType() << ")\n";
    std::cout << "  Customer: " << m_customerName << "\n";
    std::cout << "  Show:     " << m_show->getTitle()
              << " (" << m_show->getType() << ")\n";
    std::cout << "  Seat:     " << getSeatPosition()
              << " (" << m_seat->getLabel() << ")\n";
    std::cout << "  Group:    " << m_groupSize << " people"
              << " (15% discount applied)\n";
    std::cout << "  Price:    $" << std::fixed << std::setprecision(2)
              << calculatePrice() << "\n";
}
