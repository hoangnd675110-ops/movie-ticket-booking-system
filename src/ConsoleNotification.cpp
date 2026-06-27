#include "ConsoleNotification.h"
#include "ConsoleUtils.h"
#include <iostream>
#include <sstream>

void ConsoleNotification::send(const std::string& recipient, const std::string& message) const {
    std::ostringstream oss;
    oss << "\n--- Notification (" << getType() << ") ---\n"
        << "  To: " << recipient << "\n"
        << "  Message: " << message << "\n"
        << "---------------------------------\n";
    std::string line;
    std::istringstream iss(oss.str());
    while (std::getline(iss, line))
        printCentered(line);
}

std::string ConsoleNotification::getType() const { return "Console"; }
