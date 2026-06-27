#include "Customer.h"
#include <iostream>

Customer::Customer(const std::string& name, const std::string& email, const std::string& phone)
    : Person(name, email, phone), m_loyaltyPoints(0) {}

int Customer::getLoyaltyPoints() const { return m_loyaltyPoints; }
void Customer::addLoyaltyPoints(int points) { m_loyaltyPoints += points; }

std::string Customer::getDescription() const { return "Customer"; }

void Customer::displayInfo() const {
    Person::displayInfo();
    std::cout << " | Role: " << getDescription()
              << " | Loyalty Points: " << m_loyaltyPoints << "\n";
}
