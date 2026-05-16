#include <iostream>
#include <string>

#include "coffee.hpp"


int main() {
    char choice;
    Drink* order = nullptr; 
    

    std::cout<<"hi, l,m,s? ";
    std::cin >> choice; 

    switch (choice){
        case 'l': order = new LargeCoffee(); break;
        case 'm': order = new MediumCoffee(); break;
        default: order = new SmallCoffee(); break;
    }
    do {
        std::cout << "s, c, h, or d? ";
        std::cin >> choice;

        switch (choice){
            case 's': order = new Sugar(order); break;
            case 'c': order = new Cream(order); break;
            case 'h': order = new Honey(order); break;
            default: break;
        }
    } while (choice != 'd');


    std::string name;
    std::cout << "name? ";
    std::cin >> name;

    std::cout << name << ", your " << order->getName()
              << " is ready. It will be $" << order->getPrice()<<std::endl;

    delete order; 
}