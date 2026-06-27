#include "CardPayment.h"
#include <iostream>
#include <iomanip>

CardPayment::CardPayment(double amount, const std::string& cardNumber,
                         const std::string& cardHolder)
    : Payment(amount), m_cardNumber(cardNumber), m_cardHolder(cardHolder) {}

std::string CardPayment::getMaskedCardNumber() const {
    if (m_cardNumber.length() <= 4) return "****";
    return "****-****-****-" + m_cardNumber.substr(m_cardNumber.length() - 4);
}

bool CardPayment::processPayment() {
    m_status = PaymentStatus::Completed;
    return true;
}

std::string CardPayment::getPaymentMethod() const { return "Card"; }

void CardPayment::display() const {
    std::cout << "  Payment:    Card\n";
    std::cout << "  Card Holder: " << m_cardHolder << "\n";
    std::cout << "  Card Number: " << getMaskedCardNumber() << "\n";
    std::cout << "  Amount:     $" << std::fixed << std::setprecision(2) << m_amount << "\n";
    std::cout << "  Status:     " << getStatusString() << "\n";
}
