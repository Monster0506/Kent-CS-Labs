#include "drink.hpp"

class SmallCoffee: public Drink {
    public:
    SmallCoffee() : Drink(DrinkType::small, 5) {}
};

class MediumCoffee: public Drink {
    public:
    MediumCoffee() : Drink(DrinkType::medium, 7) {}
};
class LargeCoffee: public Drink {
    public:
    LargeCoffee() : Drink(DrinkType::large, 5) {}
};


class DrinkDecorator : public Drink {
public:
    DrinkDecorator(Drink* drink) : drink_(drink) {}
    ~DrinkDecorator() {delete drink_;}
    
    int getPrice() const override {return drink_->getPrice();}

    std::string getName() const override {return drink_->getName();}

protected:
    Drink* drink_;
    std::string appendIngredient(const std::string& ingredient) const {
        std::string a = drink_->getName();
        if (a.find("with") == std::string::npos)
            return a + " with " + ingredient;
        return a + ", " + ingredient;
    }
};

class Sugar : public DrinkDecorator {
public:
    Sugar(Drink* drink) : DrinkDecorator(drink) {}
int getPrice() const override {return drink_->getPrice() + 1;}
std::string getName() const override {return appendIngredient("sugar");}
};

class Cream: public DrinkDecorator {
public:
    Cream(Drink* drink) : DrinkDecorator(drink) {}
int getPrice() const override {return drink_->getPrice() + 1;}
std::string getName() const override {return appendIngredient("cream");}
};

class Honey: public DrinkDecorator {
public:
    Honey(Drink* drink) : DrinkDecorator(drink) {}
int getPrice() const override {return drink_->getPrice() + 3;}
std::string getName() const override {return appendIngredient("honey");}
};
