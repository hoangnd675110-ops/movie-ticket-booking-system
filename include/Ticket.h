#pragma once
#include <string>
#include <memory>

class Show;
class Seat;

class Ticket {
protected:
    int m_id;
    const Show* m_show;
    const Seat* m_seat;
    std::string m_customerName;

public:
    Ticket(int id, const Show* show, const Seat* seat, const std::string& customerName);
    virtual ~Ticket() = default;

    int getId() const;
    std::string getCustomerName() const;
    std::string getShowTitle() const;
    std::string getSeatLabel() const;
    std::string getSeatPosition() const;

    virtual double calculatePrice() const;
    virtual std::string getType() const;
    virtual void display() const;
};
