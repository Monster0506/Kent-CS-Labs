// sorting apples
// non STL-algorithm code to be replaced by algorthms
// Mikhail Nesterenko
// 02/19/2025


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <numeric>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector; using std::deque;
using std::generate; using std::for_each; using std::count_if; using std::find_if; using std::max_element; using std::accumulate; using std::transform;

struct Apples{
   double weight; // oz
   string color;  // red or green
   void print() const { cout << color << ", " <<  weight << endl; }
};



int main(){
   srand(time(nullptr));
   const double minWeight = 3.;
   const double maxWeight = 8.;

   cout << "Input crate size: ";
   int size;
   cin >> size;

   vector <Apples> crate(size);

   // assign random weight and color to apples in the crate
   // replace with generate()
   generate(crate.begin(), crate.end(), [=]() {
        Apples a;
        a.weight = minWeight + static_cast<double>(rand())/RAND_MAX*(maxWeight - minWeight);
        a.color = rand() %2 == 1 ? "green" : "red";    
        return a;
    });


    // for_each() possibly
   

   for_each(crate.begin(), crate.end(), [](const auto &e) {e.print();});

   
   cout << "Enter weight to find: ";
   double toFind;
   cin >> toFind;

   // count_if()

   int cnt = count_if(crate.cbegin(), crate.cend(), [&toFind](const auto &e) {return e.weight > toFind;});   

   cout << "There are " << cnt << " apples heavier than " 
	<< toFind << " oz" <<  endl;

   // find_if()
   cout << "at positions ";
   auto it = crate.begin();
   while ((it = find_if(it, crate.end(), [toFind](const auto& c) {
               return c.weight > toFind;
           })) != crate.end()) {
       cout << distance(crate.begin(), it) << ", ";
       ++it;
   }
   cout << endl;    


   // max_element()
   auto heaviest = max_element(crate.cbegin(), crate.cend(), [](const auto &a, const auto &b){return a.weight < b.weight;});
   cout << "Heaviest apple weighs: " << heaviest->weight << " oz" << endl;


   // for_each() or accumulate()

double sum = accumulate(crate.cbegin(), crate.cend(), 0.0, [](double a, const auto &b){return a+b.weight;});

   cout << "Total apple weight is: " << sum << " oz" << endl;


   // transform();
   cout << "How much should they grow: ";
   double toGrow;
   cin >> toGrow;

   transform(crate.begin(), crate.end(), crate.begin(), [&toGrow](auto &e){e.weight += toGrow; return e;})    ;

   cout << "Input minimum acceptable weight: ";
   double minAccept;
   cin >> minAccept;


   // removing small apples
   // nested loops, replace with a single loop modification idiom

   it = remove_if(crate.begin(), crate.end(), [&minAccept](const auto &e) {return e.weight < minAccept;});
   cout << "removed " << crate.end() - it << " elements" << endl;
   crate.erase(it, crate.end());


   // bubble sort, replace with sort()
    

   sort(crate.begin(), crate.end(), [](const auto &a, const auto &b){return a.weight < b.weight;});    
        

   cout << "sorted remaining apples"<< endl;
   for_each(crate.begin(), crate.end(), [](const auto &e) {e.print();});

}
