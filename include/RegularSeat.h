#pragma once
#include "Seat.h"

class RegularSeat : public Seat {
public:
    RegularSeat(int row, int col);
    double getPriceMultiplier() const override;
    std::string getLabel() const override;
};
