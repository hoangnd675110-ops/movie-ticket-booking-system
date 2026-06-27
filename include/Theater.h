#pragma once
#include <vector>
#include <memory>
#include <string>

class Seat;

class Theater {
private:
    int m_id;
    std::string m_name;
    int m_rows;
    int m_cols;
    std::vector<std::vector<std::unique_ptr<Seat>>> m_seats;

public:
    Theater(int id, const std::string& name, int rows, int cols);
    ~Theater();

    int getId() const;
    std::string getName() const;
    int getRows() const;
    int getCols() const;

    Seat* getSeat(int row, int col) const;
    bool isSeatAvailable(int row, int col) const;
    bool bookSeat(int row, int col, const std::string& customer);
    bool cancelBooking(int row, int col);
    void displaySeats() const;
    int getAvailableSeats() const;
    int getTotalSeats() const;
};
