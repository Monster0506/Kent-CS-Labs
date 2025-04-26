#include <cassert>
#include <iostream>
#include "string.hpp"

int main() {
    {
        String s("Hello World");
        assert(s.findstr(0, "World") == 6);
        assert(s.findstr(0, "Hello") == 0);
        assert(s.findstr(0, "XYZ") == -1);
    }
    std::cout << "Find String Test Passed" << std::endl;
}
