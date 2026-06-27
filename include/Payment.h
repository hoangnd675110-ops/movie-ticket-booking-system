#pragma once
#include <string>

enum class PaymentStatus {
    Pending,
    Completed,
    Failed
};

class Payment {
protected:
    double m_amount;
    PaymentStatus m_status;

public:
    Payment(double amount);
    virtual ~Payment() = default;

    double getAmount() const;
    PaymentStatus getStatus() const;
    void setStatus(PaymentStatus status);
    std::string getStatusString() const;

    virtual bool processPayment() = 0;
    virtual std::string getPaymentMethod() const = 0;
    virtual void display() const;
};
