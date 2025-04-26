#include <cassert>
#include <iostream>
#include "string.hpp"

int main() {
    {
        String s;
        std::cout << "Enter a string: ";
        std::cin >> s;  
        std::cout << "You entered: " << s << std::endl;
        assert(s.length() > 0);  
    }
    std::cout << "Input Operator Test Passed" << std::endl;
}