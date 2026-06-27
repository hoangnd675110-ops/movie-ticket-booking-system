#pragma once
#include "Person.h"

class Customer : public Person {
private:
    int m_loyaltyPoints;

public:
    Customer(const std::string& name, const std::string& email, const std::string& phone);

    int getLoyaltyPoints() const;
    void addLoyaltyPoints(int points);

    std::string getDescription() const override;
    void displayInfo() const override;
};
