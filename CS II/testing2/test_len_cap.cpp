#include <cassert>
#include <iostream>
#include "string.hpp"

int main() {
    {
        String s("Hello");
        assert(s.length() == 5);
        assert(s.capacity() == 255);
    }
    std::cout << "Length and Capacity Tests Passed" << std::endl;
}
