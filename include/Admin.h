#pragma once
#include "Person.h"

class Admin : public Person {
private:
    std::string m_staffId;

public:
    Admin(const std::string& name, const std::string& email,
          const std::string& phone, const std::string& staffId);

    std::string getStaffId() const;

    std::string getDescription() const override;
    void displayInfo() const override;
};
