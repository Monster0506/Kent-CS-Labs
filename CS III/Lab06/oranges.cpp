// selecting oranges
// converting vectors to multimaps
// Mikhail Nesterenko
// 9/26/2022


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector;
using std::multimap;

enum class Variety {orange, pear, apple};
vector<string> colors = {"red", "green", "yellow"};

struct Fruit{
   Variety v;
   string color; // red, green or yellow
};


int main(){
   srand(time(nullptr));
   int numFruit = rand()%100 + 1;
   multimap<Variety, string> tree;

   for (int i = 0; i < numFruit; ++i){
      Variety v = static_cast<Variety>(rand() % 3);
      string color = colors[rand() % 3];
      tree.emplace(v, color);
   }
   
   // printing colors of oranges
   cout << "Colors of the oranges: ";
   auto lower = tree.lower_bound(Variety::orange);
   auto upper = tree.upper_bound(Variety::orange);

   for(auto it = lower; it != upper; ++it){
      cout << it->second << ", ";
   }
   cout << endl;

}

