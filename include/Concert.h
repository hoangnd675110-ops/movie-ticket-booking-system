#pragma once
#include "Show.h"

class Concert : public Show {
private:
    std::string m_artist;

public:
    Concert(int id, const std::string& title, int duration,
            double basePrice, const std::string& artist);

    std::string getArtist() const;
    std::string getType() const override;
    void display() const override;
};
