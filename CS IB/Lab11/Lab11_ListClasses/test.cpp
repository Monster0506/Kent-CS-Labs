// testing the implementation of class list
// Mikhail Nesterenko
// 11/16/2020

#include <iostream>
#include "list.hpp"

using std::cout;
using std::endl;

int main()
{

    List c1;
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
            c1.addNumber(number);
            break;
        case 'r':
            c1.removeNumber(number);
            break;
        default:
            break;
        }
        c1.output();

    } while (c != 'q');
}
