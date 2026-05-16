#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "coffee.hpp"
#include "barista.hpp"
#include "coffeeshack.hpp"
#include "customer.hpp"

Drink* buildDrink() {
    char   choice;
    Drink* order = nullptr;

    std::cout << "hi, l, m, s? ";
    std::cin >> choice;

    switch (choice) {
        case 'l': order = new LargeCoffee();  break;
        case 'm': order = new MediumCoffee(); break;
        default:  order = new SmallCoffee();  break;
    }
    

    do {
        std::cout << "s, c, h, or d? ";
        std::cin >> choice;
        switch (choice) {
            case 's': order = new Sugar(order); break;
            case 'c': order = new Cream(order); break;
            case 'h': order = new Honey(order); break;
            default: break;
        }
    } while (choice != 'd');

    return order;
}


int main() {
    std::srand(std::time(nullptr));
    JuniorBarista junior;
    SeniorBarista senior;
    Manager manager;
    junior.setNext(&senior);
    senior.setNext(&manager);

    CoffeeShack shack;

    std::vector<Customer*> customers;

    const int CUSTOMERS = 3;
    int ordersPlaced   = 0;

    while (ordersPlaced < CUSTOMERS || shack.hasPending()) {

        bool takeOrder =
            (ordersPlaced < CUSTOMERS) &&
            (!shack.hasPending() || rand() % 2 == 0);

        if (takeOrder) {
            Drink* drink = buildDrink();

            std::string name;
            std::cout << "name? ";
            std::cin >> name;

            std::string barista = junior.handle(drink);

            Customer* customer = new Customer(name);
            customers.push_back(customer);
            shack.attach(customer);

            shack.addOrder(name, drink->getName(), drink->getPrice(), barista);
            delete drink; 

            std::cout << "Please wait, " << name << ".\n\n";
            ++ordersPlaced;
        } else {
            shack.serveRandom();
        }
    }

    for (auto* c : customers) delete c;

    return 0;
}
