#pragma once
#include "NotificationService.h"

class ConsoleNotification : public NotificationService {
public:
    void send(const std::string& recipient, const std::string& message) const override;
    std::string getType() const override;
};
