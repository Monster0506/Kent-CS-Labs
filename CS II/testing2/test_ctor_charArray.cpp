#include <cassert>
#include <iostream>
#include "string.hpp"

int main() {
    {
        String s("Hello");
        assert(s == "Hello");
        assert(s.length() == 5);
    }
    {
        String s("");
        assert(s == "");
        assert(s.length() == 0);
    }
    {
        String s("A");
        assert(s == "A");
        assert(s.length() == 1);
    }
    std::cout << "Constructor from char array Passed" << std::endl;
}
