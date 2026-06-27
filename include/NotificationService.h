#pragma once
#include <string>

class NotificationService {
public:
    virtual ~NotificationService() = default;
    virtual void send(const std::string& recipient, const std::string& message) const = 0;
    virtual std::string getType() const = 0;
};
