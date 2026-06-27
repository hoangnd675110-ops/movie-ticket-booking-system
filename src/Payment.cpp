#include "Payment.h"
#include <iostream>
#include <iomanip>

Payment::Payment(double amount)
    : m_amount(amount), m_status(PaymentStatus::Pending) {}

double Payment::getAmount() const { return m_amount; }
PaymentStatus Payment::getStatus() const { return m_status; }
void Payment::setStatus(PaymentStatus status) { m_status = status; }

std::string Payment::getStatusString() const {
    switch (m_status) {
        case PaymentStatus::Pending:   return "Pending";
        case PaymentStatus::Completed: return "Completed";
        case PaymentStatus::Failed:    return "Failed";
    }
    return "Unknown";
}

void Payment::display() const {
    std::cout << "  Amount: $" << std::fixed << std::setprecision(2) << m_amount
              << " | Method: " << getPaymentMethod()
              << " | Status: " << getStatusString() << "\n";
}
