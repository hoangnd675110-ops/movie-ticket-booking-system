#pragma once
#include "Ticket.h"

class StandardTicket : public Ticket {
public:
    StandardTicket(int id, const Show* show, const Seat* seat,
                   const std::string& customerName);
    std::string getType() const override;
};
