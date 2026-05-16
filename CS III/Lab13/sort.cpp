// using sorting algorihtms to demonstrate the Strategy Design Pattern
// Mikhail Nesterenko
// 4/23/2026

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using std::cout; using std::endl;
using std::vector; 

typedef vector<int>::iterator It;  // shorthand for a vector iterator

// abstract strategy
// strategy interface, push method
class Sorter{
public:
   virtual void sort(It, It) const = 0;
};


// context using the strategies
class OrderedCollection{
public:
   void setSorter(Sorter *sorter) {sorter_ = sorter;}
   void setCollection(const vector<int> &v){v_ = v;}
   const vector<int>& getCollection() const{ return v_;}
   void sort() {sorter_->sort(v_.begin(), v_.end());}
private:
   vector<int> v_;
   Sorter *sorter_; 
};


// concrete strategy using bubble sort
class BubbleSorter: public Sorter {
public:
   void sort(It begin, It end) const override {
      bool swapped;
      do{
	 swapped = false;
	 for(It one=begin, two = next(one, 1); two != end; ++one, ++two)
	    if(*one > *two){
	       std::swap(*one, *two);
	       swapped=true;
	    }
      }while(swapped);
   }
};

class InsertionSorter: public Sorter {
public:
    void sort(It begin, It end) const override {
        for(It i = next(begin); i!=end; i++ ){
            for(It j = i; j!=begin; ) {
                It pre = prev(j);
                if (*j < *pre)
                    std::swap(*j, *pre);
                else
                    break;
                j = pre;
            } 
        }   
    }

};



// concrete strategy using STL sorting alg
class StdSorter: public Sorter{
public:
   void sort(It begin, It end) const override {
      std::sort(begin, end);
   }
};


int main() {
   vector<int> v={2012, 69, 582, -17, 27, 420, -9, 7007}, vc=v, vd=v;

   OrderedCollection sortedVector;
   StdSorter ss;
   BubbleSorter bs;
   InsertionSorter is;

   // 
   // sorting short vectors to demo correctness
   //

   // STL sorter
   cout << "Original vector v" << endl;
   for(auto e: v) cout << e << " "; cout << endl << endl;
   sortedVector.setSorter(&ss);
   sortedVector.setCollection(v);
   sortedVector.sort();
   v = sortedVector.getCollection();
   cout << "STL sorted" << endl; 
   for(auto e: v) cout << e << " "; cout << endl << endl;

   // BubbleSort sorter
   cout << "Original vector vc" << endl;
   for(auto e: vc) cout << e << " "; cout << endl;
   sortedVector.setSorter(&bs);
   sortedVector.setCollection(vc);
   sortedVector.sort();
   vc = sortedVector.getCollection();
   cout << "bubble sorted" << endl; 
   for(auto e: vc) cout << e << " "; cout << endl << endl;

  
   
   // 
   // sorting large vectors to demo performance
   // 
   v.clear();
   srand(time(nullptr));

   std::generate_n(back_inserter(v), 50'000, []{return rand()%100;});
   vc=v;
   vd=v;

   std::chrono::time_point<std::chrono::high_resolution_clock>
      startTime, endTime; // chrono time points
   std::chrono::duration<double> duration; 
                          // chrono time interval

   // STL sorter
   sortedVector.setSorter(&ss);
   sortedVector.setCollection(v);

   startTime = std::chrono::high_resolution_clock::now();
   sortedVector.sort();
   endTime = std::chrono::high_resolution_clock::now();
   duration = endTime - startTime;
   cout << "standard sort ran for " << duration.count() << " seconds" << endl;
   v = sortedVector.getCollection();
   
   // bubble sort
   sortedVector.setSorter(&bs);
   sortedVector.setCollection(vc);
   
   startTime = std::chrono::high_resolution_clock::now();
   sortedVector.sort();
   endTime = std::chrono::high_resolution_clock::now();
   duration = endTime - startTime;
   vc = sortedVector.getCollection();

   cout << "bubble sort ran for " << duration.count() << " seconds" << endl;


   // insertion sort
   sortedVector.setSorter(&is);
   sortedVector.setCollection(vd);
   
   startTime = std::chrono::high_resolution_clock::now();
   sortedVector.sort();
   endTime = std::chrono::high_resolution_clock::now();
   duration = endTime - startTime;
   vd = sortedVector.getCollection();

   cout << "insertion sort ran for " << duration.count() << " seconds" << endl;

   
   // confirming sorted vectors are the same
   if(v == vc && vc == vd)
      cout << "sorted vectors are the same" << endl;
   else {
      cout << "sorted vectors are different" << endl;  
      vector<vector<int>> vecs = {v, vc, vd};
      for_each(vecs.begin(), vecs.end(), [](const auto &vec){
        for_each(vec.begin(), vec.begin() + 5, [](const auto &a){cout <<a <<",";});
     });
    }
}
