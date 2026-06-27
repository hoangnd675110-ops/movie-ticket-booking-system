#include "Seat.h"

Seat::Seat(int row, int col)
    : m_row(row), m_col(col), m_status(SeatStatus::Available), m_customerName("") {}

int Seat::getRow() const { return m_row; }
int Seat::getCol() const { return m_col; }
SeatStatus Seat::getStatus() const { return m_status; }
std::string Seat::getCustomerName() const { return m_customerName; }

bool Seat::isAvailable() const { return m_status == SeatStatus::Available; }

bool Seat::book(const std::string& customer) {
    if (!isAvailable()) return false;
    m_status = SeatStatus::Booked;
    m_customerName = customer;
    return true;
}

bool Seat::cancel() {
    if (isAvailable()) return false;
    m_status = SeatStatus::Available;
    m_customerName = "";
    return true;
}

std::string Seat::getLabel() const { return "Standard"; }

double Seat::getFinalPrice(double basePrice) const {
    return basePrice * getPriceMultiplier();
}
