// drink class to be used in Coffee Shack lab
// Mikhail Nesterenko
// 11/7/2022

#include <string>

enum class DrinkType {small, medium, large};

class Drink{
public:
   Drink(DrinkType type=DrinkType::small, int price=0):
                 type_(type), price_(price){}
   virtual int getPrice() const;
   virtual std::string getName() const;
private: 
   int price_;
   DrinkType type_;
};
