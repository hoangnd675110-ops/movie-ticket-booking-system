#include "Person.h"
#include <iostream>

Person::Person(const std::string& name, const std::string& email, const std::string& phone)
    : m_name(name), m_email(email), m_phone(phone) {}

std::string Person::getName() const { return m_name; }
std::string Person::getEmail() const { return m_email; }
std::string Person::getPhone() const { return m_phone; }

void Person::displayInfo() const {
    std::cout << "Name: " << m_name << " | Email: " << m_email
              << " | Phone: " << m_phone;
}
