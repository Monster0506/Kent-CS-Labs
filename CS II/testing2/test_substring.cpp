#include <cassert>
#include <iostream>
#include "string.hpp"

int main() {
    {
        String s("Hello World");
        assert(s.substr(0, 4) == "Hello");
        assert(s.substr(6, 10) == "World");
        assert(s.substr(3, 3) != "l");
    }
    std::cout << "Substring Test Passed" << std::endl;
}
