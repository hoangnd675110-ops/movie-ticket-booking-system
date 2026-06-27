#pragma once
#include "Ticket.h"

class GroupTicket : public Ticket {
private:
    int m_groupSize;

public:
    GroupTicket(int id, const Show* show, const Seat* seat,
                const std::string& customerName, int groupSize);

    int getGroupSize() const;
    double calculatePrice() const override;
    std::string getType() const override;
    void display() const override;
};
