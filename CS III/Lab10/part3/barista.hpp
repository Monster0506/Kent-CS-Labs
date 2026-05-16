#include <iostream>
#include <string>
#include "drink.hpp"

class Barista {

public:
    Barista(const std::string& title): title_(title), sucessor_(nullptr){}
    virtual ~Barista() = default;
    
    void setNext(Barista* sucessor__){sucessor_ = sucessor__;}
    

    std::string handle(Drink* order){
        if (canHandle(order)) 
            return title_;
        else if (sucessor_)
            return sucessor_->handle(order);
        else
            return "nothing";
    }    
protected:
    virtual bool canHandle(Drink *order) const = 0;
    void serve(Drink* order, const std::string& name){
    std::cout << "I, " << title_ << " have prepared your drink" << std::endl;
    std::cout << name << ", your " << order->getName() << " is ready. It will be $" << order->getPrice()<<std::endl;
    }
private:
    std::string title_;
    Barista* sucessor_;
};


class JuniorBarista : public Barista {
public:
    JuniorBarista() : Barista("Junior Barista") {}
protected:
    bool canHandle(Drink* order) const override {
        return order->getName().find("with") == std::string::npos;
    }
};


class SeniorBarista : public Barista {
public:
    SeniorBarista() : Barista("Senior Barista") {}
protected:
    bool canHandle(Drink* order) const override {
        return order->getName().find("honey") == std::string::npos;
    }
};

class Manager : public Barista {
public:
    Manager() : Barista("Manager") {}
protected:
    bool canHandle(Drink* order) const override {
        return true; 
    }
};