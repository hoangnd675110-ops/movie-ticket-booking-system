#include "VIPSeat.h"

VIPSeat::VIPSeat(int row, int col) : Seat(row, col) {}

double VIPSeat::getPriceMultiplier() const { return 1.5; }

std::string VIPSeat::getLabel() const { return "VIP"; }
