#pragma once
#include "Show.h"

class Movie : public Show {
private:
    std::string m_genre;

public:
    Movie(int id, const std::string& title, int duration,
          double basePrice, const std::string& genre);

    std::string getGenre() const;
    std::string getType() const override;
    void display() const override;
};
