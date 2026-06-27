#pragma once
#include <string>

class Show {
protected:
    int m_id;
    std::string m_title;
    int m_duration;
    double m_basePrice;

public:
    Show(int id, const std::string& title, int duration, double basePrice);
    virtual ~Show() = default;

    int getId() const;
    std::string getTitle() const;
    int getDuration() const;
    double getBasePrice() const;

    virtual double getPrice() const;
    virtual std::string getType() const = 0;
    virtual void display() const;
};
