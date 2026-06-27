#include "CashPayment.h"
#include <iostream>
#include <iomanip>

CashPayment::CashPayment(double amount, double cashTendered)
    : Payment(amount), m_cashTendered(cashTendered) {}

double CashPayment::getCashTendered() const { return m_cashTendered; }

double CashPayment::getChange() const {
    return m_cashTendered - m_amount;
}

bool CashPayment::processPayment() {
    if (m_cashTendered >= m_amount) {
        m_status = PaymentStatus::Completed;
        return true;
    }
    m_status = PaymentStatus::Failed;
    return false;
}

std::string CashPayment::getPaymentMethod() const { return "Cash"; }

void CashPayment::display() const {
    std::cout << "  Payment: Cash\n";
    std::cout << "  Amount:  $" << std::fixed << std::setprecision(2) << m_amount << "\n";
    std::cout << "  Tendered: $" << m_cashTendered << "\n";
    std::cout << "  Change:  $" << getChange() << "\n";
    std::cout << "  Status:  " << getStatusString() << "\n";
}
