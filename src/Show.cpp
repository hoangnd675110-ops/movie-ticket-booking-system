#include "Show.h"
#include <iostream>
#include <iomanip>

Show::Show(int id, const std::string& title, int duration, double basePrice)
    : m_id(id), m_title(title), m_duration(duration), m_basePrice(basePrice) {}

int Show::getId() const { return m_id; }
std::string Show::getTitle() const { return m_title; }
int Show::getDuration() const { return m_duration; }
double Show::getBasePrice() const { return m_basePrice; }

double Show::getPrice() const { return m_basePrice; }

void Show::display() const {
    std::cout << "[" << m_id << "] " << m_title
              << " (" << getType() << ")"
              << " | " << m_duration << " min"
              << " | $" << std::fixed << std::setprecision(2) << m_basePrice;
}
