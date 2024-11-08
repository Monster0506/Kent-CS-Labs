// tests list implementation
// Mikhail Nesterenko
// 11/2/2020

#include "list.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{

    int size = 5;                 // setting list array size
    double *a = new double[size]; // allocating dynamic array

    // initializing array
    a[0] = 0.;
    a[1] = 10.;
    a[2] = 20.;
    a[3] = 30.;
    a[4] = 40.;

    output(a, size); // printing out the array

    // asking user to input a number
    cout << "Input number to find in the list: ";
    double number;
    cin >> number;

    // checking if the input number is in the list
    int index = check(a, number, size);
    if (index == -1)
        cout << "The number is not in the array" << endl;
    else
        cout << "The number is at position " << index << endl;

    // adding a new number to the list
    addNumber(a, 55.5, size);
    cout << "list after adding a new number: ";
    output(a, size);

    // adding a duplicate number to list
    // the function should not add it
    addNumber(a, 20., size);
    cout << "list after adding existing number: ";
    output(a, size);

    
    removeNumber(a, 10., size);
    cout << "list after removing number: ";
    output(a, size);

    delete[] a; // deallocating the array
}