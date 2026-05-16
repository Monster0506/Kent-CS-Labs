// needed for lab
// Mikhail Nesterenko
// 3/18/2022

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "CarFactory.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

class CarLot {
   public:
    CarLot();
    Car *nextCar();
    int lotSize() const { return cars_.size(); }

    // if a car is bought, requests a new one
    Car *buyCar(Car *car);
    //     Car *bought = car4sale_;
    //     car4sale_ = factories_[rand() % factories_.size()]->requestCar();
    //     return bought;
    // }

   private:
    vector<CarFactory *> factories_;
    vector<Car *> cars_;
    int curr;
};

CarLot::CarLot() {
    // creates 2 Ford factories and 2 Toyota factories
    factories_.push_back(new FordFactory());
    factories_.push_back(new ToyotaFactory());
    factories_.push_back(new FordFactory());
    factories_.push_back(new ToyotaFactory());

    std::generate_n(std::back_inserter(cars_), 8, [&]() {
        return factories_[rand() % factories_.size()]->requestCar();
    });
    // Car *car4sale_ = factories_[rand() % factories_.size()]->requestCar();
}

CarLot *carLotPtr = nullptr;  // global pointer instantiation
Car *CarLot::nextCar() {
    if (cars_.empty()) return nullptr;
    Car *car = cars_[curr];
    curr = (curr + 1) % cars_.size();
    return car;
}
Car *CarLot::buyCar(Car *car) {
    for (auto it = cars_.begin(); it != cars_.end(); ++it) {
        if (*it == car) {
            cars_.erase(it);
            break;
        }
    }
    // replace with a new random car
    cars_.push_back(factories_[rand() % factories_.size()]->requestCar());
    curr = 0;
    return car;
}

// test-drives a car
// buys it if Toyota
void toyotaLover(int id, const string &model) {
    if (carLotPtr == nullptr) carLotPtr = new CarLot();

    cout << "Jill Toyoter: model: " << model << " " << id << endl;

    int attempts = carLotPtr->lotSize();
    for (int i = 0; i < attempts; i++) {
        Car *toBuy = carLotPtr->nextCar();
        cout << "test driving " << toBuy->getMake() << " " << toBuy->getModel();

        if (toBuy->getMake() == "Toyota" && toBuy->getModel() == model) {
            cout << " love it! buying it!" << endl;
            carLotPtr->buyCar(toBuy);
            return;
        } else
            cout << " did not like it!" << endl;
    }
    cout << "Going home" << endl;
}

// test-drives a car
// buys it if Ford
void fordLover(int id, const string &model) {
    if (carLotPtr == nullptr) carLotPtr = new CarLot();

    cout << "Jack Fordman: model: " << model << " " << id << endl;

    int attempts = carLotPtr->lotSize();
    for (int i = 0; i < attempts; i++) {
        Car *toBuy = carLotPtr->nextCar();
        cout << "test driving " << toBuy->getMake() << " " << toBuy->getModel();

        if (toBuy->getMake() == "Ford" && toBuy->getModel() == model) {
            cout << " love it! buying it!" << endl;
            carLotPtr->buyCar(toBuy);
            return;
        } else
            cout << " did not like it!" << endl;
    }
    cout << "Going home" << endl;
}

int main() {
    srand(time(nullptr));
    const vector<string> fordModels = {"Focus", "Mustang", "Explorer", "F-150"};
    const vector<string> toyotaModels = {"Corolla", "Camry", "Prius", "4Runner",
                                         "Yaris"};
    const int numBuyers = 20;
    for (int i = 0; i < numBuyers; ++i)
        if (rand() % 2 == 0) {
            string model = toyotaModels[rand() % toyotaModels.size()];
            toyotaLover(i, model);
        } else {
            string model = fordModels[rand() % fordModels.size()];
            fordLover(i, model);
        }
}
