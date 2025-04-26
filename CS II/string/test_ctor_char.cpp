#include <cassert>
#include <iostream>
#include "string.hpp"

int main() {
    {
        String s('A');
        assert(s == "A");
        assert(s.length() == 1);
    }
    {
        String s('\0');
        assert(s == "");
        assert(s.length() == 0);
    }
    std::cout << "Constructor from single character Passed" << std::endl;
}
