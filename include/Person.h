#pragma once
#include <string>

class Person {
protected:
    std::string m_name;
    std::string m_email;
    std::string m_phone;

public:
    Person(const std::string& name, const std::string& email, const std::string& phone);
    virtual ~Person() = default;

    std::string getName() const;
    std::string getEmail() const;
    std::string getPhone() const;

    virtual std::string getDescription() const = 0;
    virtual void displayInfo() const;
};
