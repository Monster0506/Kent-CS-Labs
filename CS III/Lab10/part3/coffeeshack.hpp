#pragma once
#include <vector>
#include <string>
#include <cstdlib>
#include "observer.hpp"

class CoffeeShack : public Subject {
public:
    struct PendingOrder {
        std::string customerName;
        std::string drinkName;
        int         price;
        std::string baristaTitle;
    };

    void addOrder(const std::string& customerName,
                  const std::string& drinkName,
                  int                price,
                  const std::string& baristaTitle) {
        pendingOrders_.push_back({customerName, drinkName, price, baristaTitle});
    }

    bool hasPending() const { return !pendingOrders_.empty(); }

    void serveRandom() {
        int idx = std::rand() % static_cast<int>(pendingOrders_.size());
        const PendingOrder& o = pendingOrders_[idx];
        std::cout << "\n";
        notifyObservers(o.customerName, o.drinkName, o.price, o.baristaTitle);
        pendingOrders_.erase(pendingOrders_.begin() + idx);
    }

    void serveAll() {
        while (hasPending())
            serveRandom();
    }

private:
    std::vector<PendingOrder> pendingOrders_;
};