#pragma once
#include "Seat.h"

class VIPSeat : public Seat {
public:
    VIPSeat(int row, int col);
    double getPriceMultiplier() const override;
    std::string getLabel() const override;
};
