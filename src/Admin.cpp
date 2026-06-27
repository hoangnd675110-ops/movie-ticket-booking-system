#include "Admin.h"
#include <iostream>

Admin::Admin(const std::string& name, const std::string& email,
             const std::string& phone, const std::string& staffId)
    : Person(name, email, phone), m_staffId(staffId) {}

std::string Admin::getStaffId() const { return m_staffId; }
std::string Admin::getDescription() const { return "Admin"; }

void Admin::displayInfo() const {
    Person::displayInfo();
    std::cout << " | Role: " << getDescription()
              << " | Staff ID: " << m_staffId << "\n";
}
