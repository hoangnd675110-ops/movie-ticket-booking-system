#include "Movie.h"
#include <iostream>

Movie::Movie(int id, const std::string& title, int duration,
             double basePrice, const std::string& genre)
    : Show(id, title, duration, basePrice), m_genre(genre) {}

std::string Movie::getGenre() const { return m_genre; }
std::string Movie::getType() const { return "Movie"; }

void Movie::display() const {
    Show::display();
    std::cout << " | Genre: " << m_genre << "\n";
}
