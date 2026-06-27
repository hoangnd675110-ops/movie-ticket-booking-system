#include "Concert.h"
#include <iostream>

Concert::Concert(int id, const std::string& title, int duration,
                 double basePrice, const std::string& artist)
    : Show(id, title, duration, basePrice), m_artist(artist) {}

std::string Concert::getArtist() const { return m_artist; }
std::string Concert::getType() const { return "Concert"; }

void Concert::display() const {
    Show::display();
    std::cout << " | Artist: " << m_artist << "\n";
}
