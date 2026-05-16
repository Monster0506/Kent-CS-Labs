// mediator-based air traffic control
// Mikhail Nesterenko
// 11/30/2022

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <map>

// for timed sleep
#include <thread>
#include <chrono>


using std::cout; using std::cin; using std::endl;
using std::string;


class Logo {
public:
    virtual string display() const = 0;
    virtual ~Logo() = default;
};


class AirlineLogo : public Logo {
    string upper_;
public: 
    AirlineLogo(const string &name) {
        for (char c : name)
            upper_ += toupper(c);
    }
    string display() const override {return upper_;}
};


class LogoFactory {
    static std::map<string, Logo*> logos_;
public:
    static Logo *getLogo(const string &airline){
        auto it =logos_.find(airline);
        if (it == logos_.end()){
            logos_[airline] = new AirlineLogo(airline);
            it = logos_.find(airline);
        }   
        return it->second;
    }
};

std::map<string, Logo *> LogoFactory::logos_;


// abstract mediator
class Controller{
public:
   virtual void join(class Flight*)=0;
   virtual void leave(class Flight*)=0;
   virtual void broadcast() = 0;
   virtual void observe() = 0;
};


// concrete mediator
// tower, runway clearance
class Tower: public Controller{
public:
   void join(class Flight*) override; 
   void leave(class Flight*) override;
   void broadcast() override;
   void observe() override;
private:
   std::set<class Flight*> waiting_;
};


// abstract colleague
class Flight {
public:
   Flight(Controller *controller):controller_(controller),
				  status_(Status::waiting){
      task_ = rand() % 2 ? Task::taxiing : Task::approaching;
      controller_->join(this);
   }
   void receive(const string &msg){
      if (msg.find(flightNo_) != string::npos || msg.find("all") != string::npos){
	 if(msg.find("clear") != string::npos){
	    cout << flightNo_ << " roger that, ";
	    cout << (task_ == Task::taxiing ? "taking off" : "landing") << endl;
	    status_ = Status::cleared;
	 } else if(msg.find("status") != string::npos) {
	    cout << flightNo_
		 << (status_ == Status::waiting ? " waiting to " : " cleared to ")   
	         << (task_ == Task::taxiing ? "take off" : "land") << endl;
	 } else
	    cout << "Tower, this is " << flightNo_ << " please repeat." << endl;
      }
   }
   bool isCleared() const {return status_ == Status::cleared;}
   void proceed(){
      std::this_thread::sleep_for(std::chrono::seconds(rand()%3+1)); // wait a while    
      const string action = task_ == Task::taxiing ? "takes off":"lands";
      cout << logo_->display()
	   << flightNo_.substr(airline_.size()) << " "
	   << action <<". Have a good day!" << endl; 
      controller_->leave(this);
   }

protected:
   string flightNo_;
   Controller *controller_;
   enum class Task {taxiing, approaching};  Task task_;
   enum class Status {waiting, cleared};    Status status_;
   string airline_;
   Logo *logo_ = nullptr;
};

// concrete colleagues
class Airbus: public Flight{
public:
   Airbus(Tower *tower): Flight(tower){
      static const std::vector<string> companies = 
	 {"AirFrance", "KLM", "Aeroflot", "Lufthansa"};
      airline_ = companies[rand() % companies.size()];
      flightNo_ = airline_ +
	          std::to_string(rand() % 1000);
      logo_ = LogoFactory::getLogo(airline_);
      cout << flightNo_ << " requesting "
	   << (task_ == Task::taxiing ? "takeoff" : "landing") << endl;
   }
};

class Boeing: public Flight{
public:
   Boeing(Tower *tower): Flight(tower){
      static const std::vector<string> companies = 
	 {"Delta", "Alaskan", "Spirit"};
      airline_ = companies[rand() % companies.size()];
      flightNo_ = airline_ +
	          std::to_string(rand() % 1000);
      logo_ = LogoFactory::getLogo(airline_);
      cout << flightNo_ << " requesting "
	   << (task_ == Task::taxiing ? "takeoff" : "landing") << endl;
   }
};


// member functions for Tower
void Tower::broadcast() {
   cout << "Tower: ";
   string msg;
   getline(cin,msg);
   if(!msg.empty())
      for(auto f: waiting_) f->receive(msg);
}


void Tower::observe() {
   auto findCleared = [](Flight *f){return f->isCleared();};
   
   auto toProceed = std::find_if(waiting_.begin(), waiting_.end(), findCleared);
   
   while (toProceed != waiting_.end()){ // found a cleared flight
      (*toProceed) -> proceed();
      toProceed = std::find_if(waiting_.begin(), waiting_.end(), findCleared);
      if(toProceed != waiting_.end())
	 // more than a single flight cleared
	 cout << "MAYDAY! MAYDAY! MAYDAY! " << endl; 
   }
}

void Tower::join(Flight *f) {
   waiting_.insert(f);
}

void Tower::leave(Flight *f) {
   waiting_.erase(f);
   delete f;
}

int main(){
   srand(time(nullptr));
   Tower jfk;

   new Boeing(&jfk);
   new Airbus(&jfk);
   new Boeing(&jfk);
   new Airbus(&jfk);

   while(true){
      jfk.broadcast();
      jfk.observe();
      if(rand() % 2){
	 if (rand() % 2)
	    new Boeing(&jfk);
	 else
	    new Airbus(&jfk);
      }
   }
}
