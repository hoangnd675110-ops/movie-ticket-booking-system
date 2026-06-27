#include "StandardTicket.h"

StandardTicket::StandardTicket(int id, const Show* show, const Seat* seat,
                               const std::string& customerName)
    : Ticket(id, show, seat, customerName) {}

std::string StandardTicket::getType() const { return "Standard"; }
