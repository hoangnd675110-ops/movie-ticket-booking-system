#include "Theater.h"
#include "RegularSeat.h"
#include "VIPSeat.h"
#include <iostream>
#include <iomanip>

Theater::Theater(int id, const std::string& name, int rows, int cols)
    : m_id(id), m_name(name), m_rows(rows), m_cols(cols) {
    m_seats.resize(rows);
    for (int r = 0; r < rows; ++r) {
        m_seats[r].reserve(cols);
        for (int c = 0; c < cols; ++c) {
            if ((r + c) % 3 == 0)
                m_seats[r].push_back(std::make_unique<VIPSeat>(r, c));
            else
                m_seats[r].push_back(std::make_unique<RegularSeat>(r, c));
        }
    }
}

Theater::~Theater() = default;

int Theater::getId() const { return m_id; }
std::string Theater::getName() const { return m_name; }
int Theater::getRows() const { return m_rows; }
int Theater::getCols() const { return m_cols; }

Seat* Theater::getSeat(int row, int col) const {
    if (row < 0 || row >= m_rows || col < 0 || col >= m_cols)
        return nullptr;
    return m_seats[row][col].get();
}

bool Theater::isSeatAvailable(int row, int col) const {
    Seat* s = getSeat(row, col);
    return s && s->isAvailable();
}

bool Theater::bookSeat(int row, int col, const std::string& customer) {
    Seat* s = getSeat(row, col);
    return s && s->book(customer);
}

bool Theater::cancelBooking(int row, int col) {
    Seat* s = getSeat(row, col);
    return s && s->cancel();
}

void Theater::displaySeats() const {
    std::cout << "     ";
    for (int c = 0; c < m_cols; ++c)
        std::cout << std::setw(5) << (c + 1);
    std::cout << "\n";

    for (int r = 0; r < m_rows; ++r) {
        std::cout << "  " << static_cast<char>('A' + r) << " ";
        for (int c = 0; c < m_cols; ++c) {
            const Seat* s = m_seats[r][c].get();
            std::cout << " ";
            if (s->isAvailable())
                std::cout << "[ ]";
            else
                std::cout << "[X]";
            if (s->getLabel() == "VIP")
                std::cout << "V";
            else
                std::cout << " ";
        }
        std::cout << "\n";
    }
    std::cout << "  [ ] = Available  [X] = Booked  V = VIP Seat\n";
}

int Theater::getAvailableSeats() const {
    int count = 0;
    for (int r = 0; r < m_rows; ++r)
        for (int c = 0; c < m_cols; ++c)
            if (m_seats[r][c]->isAvailable())
                ++count;
    return count;
}

int Theater::getTotalSeats() const { return m_rows * m_cols; }
