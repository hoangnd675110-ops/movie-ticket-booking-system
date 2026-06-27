#pragma once
#include <string>

enum class SeatStatus {
    Available,
    Booked
};

class Seat {
protected:
    int m_row;
    int m_col;
    SeatStatus m_status;
    std::string m_customerName;

public:
    Seat(int row, int col);
    virtual ~Seat() = default;

    int getRow() const;
    int getCol() const;
    SeatStatus getStatus() const;
    std::string getCustomerName() const;

    bool isAvailable() const;
    bool book(const std::string& customer);
    bool cancel();

    virtual double getPriceMultiplier() const = 0;
    virtual std::string getLabel() const;
    virtual double getFinalPrice(double basePrice) const;
};
