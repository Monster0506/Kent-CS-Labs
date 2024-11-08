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

    int size = 0;                 // setting list array size
    double *a = new double[size]; // allocating dynamic array
    char c;
    int number;
    do
    {
        std::cout << "enter operation [a/r/q] and number: ";
        std::cin >> c;
        std::cin >> number;

        switch (c)
        {
        case 'a':
            addNumber(a, number, size);
            break;
        case 'r':
            removeNumber(a, number, size);
            break;
        default:
            break;
        }
        output(a, size);

    } while (c != 'q');
}