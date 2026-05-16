// testing the implementation of templated list collection
// Mikhail Nesterenko
// 1/21/2025

#include <cassert>
#include <iostream>

#include "testCollection.hpp"  // list template
using namespace std;

template <typename T>
void testfunc(Collection<T>);  // function to test pass-by-value for collection

int main() {
    // manipulating integers
    Collection<int> cone, emptyCol;
    cout << "Integer collection: ";
    cout << "adding 1 ";
    cone.add(1);
    assert(cone.last() == 1);
    cout << "adding 2 ";
    cone.add(2);
    assert(cone.last() == 2);
    cout << "adding 3 ";
    cone.add(3);
    assert(cone.last() == 3);
    cout << "adding duplicate 2 ";
    cone.add(2);
    assert(cone.last() == 2);
    cout << endl;

    cone.print();

    cout << "removing 2 ";
    cone.remove(2);
    cout << endl;

    cone.print();

    assert(cone.last() == 3);
    assert(equal(cone, cone));
    cone.remove(3);
    cone.remove(1);

    assert(equal(cone, emptyCol));

    // manipulating strings
    string sa[] = {"yellow", "orange", "green", "blue"};
    Collection<string> ctwo;

    cout << "adding an array of strings ";
    for(auto s : sa)
       ctwo.add(s);

    cout << "String collection: ";
    ctwo.print();


    // manipulating character collections

    // individal collections
    Collection<char> a2g, h2n, o2u;
    cout << "Populating individual character collections" << endl;
    for(char c='a'; c <='g'; ++c) {
       a2g.add(c);
       assert(a2g.last() == c);
    }
    for(char c='h'; c <='n'; ++c) h2n.add(c);
    for(char c='o'; c <='u'; ++c) o2u.add(c);


    assert(!equal(a2g, h2n));

    // collection of collections
    Collection<Collection<char>> cpile;

    cout << "Adding individual collections " << endl;
    cpile.add(a2g);
    assert(equal(cpile.last(), a2g));
    cpile.add(h2n);
    assert(equal(cpile.last(), h2n));
    cpile.add(o2u);
    assert(equal(cpile.last(), o2u));

    // printing characters from last collection added
    cout << "Last added character collection: ";
    cpile.last().print();
     // uncomment when you debugged the code above
     Collection<double> c1, c2, c3;

     c1.add(1.1);
     assert(c1.last() == 1.1);
     c1.add(2.2);
     assert(c1.last() == 2.2);

     testfunc(c1); // testing copy constructor
     cout << "c1 after testfunc() call: ";
     c1.print(); // if destructor is implemented correctly
                 // this should print properly after testfunc() completes

     c3=c2=c1; // testing stackability of the overloaded assignment
     cout << "c3 after stackable assingment: ";
     c3.print();

     c3=c3; // testing protection against self-assingment
     cout << "c3 after self-assignment: ";
     c3.print();
}

template <typename T>
void testfunc(Collection<T> c){ // copy constructor is invoked on "c"
    cout << "parameter c: ";
    c.print();
} // destructor is invoked when "c" goes out of scope
