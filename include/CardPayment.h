#pragma once
#include "Payment.h"
#include <string>

class CardPayment : public Payment {
private:
    std::string m_cardNumber;
    std::string m_cardHolder;

public:
    CardPayment(double amount, const std::string& cardNumber,
                const std::string& cardHolder);

    std::string getMaskedCardNumber() const;

    bool processPayment() override;
    std::string getPaymentMethod() const override;
    void display() const override;
};
