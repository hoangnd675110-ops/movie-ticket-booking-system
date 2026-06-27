#include "RegularSeat.h"

RegularSeat::RegularSeat(int row, int col) : Seat(row, col) {}

double RegularSeat::getPriceMultiplier() const { return 1.0; }

std::string RegularSeat::getLabel() const { return "Regular"; }
