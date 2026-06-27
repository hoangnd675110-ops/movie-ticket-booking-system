#pragma once
#include "Payment.h"

class CashPayment : public Payment {
private:
    double m_cashTendered;

public:
    CashPayment(double amount, double cashTendered);

    double getCashTendered() const;
    double getChange() const;

    bool processPayment() override;
    std::string getPaymentMethod() const override;
    void display() const override;
};
