#include "drink.hpp"

int Drink::getPrice() const { return price_; }

std::string Drink::getName() const {
    switch (type_) {
        case DrinkType::small: return "small coffee";
        case DrinkType::medium: return "small coffee";
        case DrinkType::large: return "small coffee";
        default: return "coffee";
    }
}