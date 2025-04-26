#include <cassert>
#include <iostream>
#include "string.hpp"

int main() {
    {
        String s("Hello");
        assert(s[0] == 'H');
        assert(s[4] == 'o');
    }
    std::cout << "Subscript Operator Passed" << std::endl;
}
