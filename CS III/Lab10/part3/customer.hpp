#pragma once
#include <iostream>
#include <string>
#include "observer.hpp"

class Customer : public Observer {
public:
    explicit Customer(const std::string& name) : name_(name) {}

    const std::string& getName() const { return name_; }

    void update(const std::string& customerName,
                const std::string& drinkName,
                int                price,
                const std::string& baristaTitle) override {
        if (customerName == name_) {
            std::cout << name_ << ", your " << drinkName
                      << " is ready. It is prepared by a " << baristaTitle
                      << ". It will be $" << price << ", please.\n";
            std::cout << "This is " << name_
                      << ", I got my coffee, thank you!\n";
        }
    }

private:
    std::string name_;
};