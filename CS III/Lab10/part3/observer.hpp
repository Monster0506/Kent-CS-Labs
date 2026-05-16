#pragma once
#include <vector>
#include <string>
#include <algorithm>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const std::string& customerName,
                        const std::string& drinkName,
                        int                price,
                        const std::string& baristaTitle) = 0;
};

class Subject {
public:
    virtual ~Subject() = default;

    void attach(Observer* obs) {
        observers_.push_back(obs);
    }

    void detach(Observer* obs) {
        observers_.erase(
            std::remove(observers_.begin(), observers_.end(), obs),
            observers_.end()
        );
    }

protected:
    void notifyObservers(const std::string& customerName,
                         const std::string& drinkName,
                         int                price,
                         const std::string& baristaTitle) {
        for (auto* obs : observers_)
            obs->update(customerName, drinkName, price, baristaTitle);
    }

private:
    std::vector<Observer*> observers_;
};