#include <cassert>
#include <iostream>
#include "string.hpp"

int main() {
    {
        String s("Hello World");
        assert(s.findch(0, 'W') == 6);
        assert(s.findch(0, 'o') == 4);
        assert(s.findch(7, 'o') == 7);
        assert(s.findch(0, 'x') == -1);
    }
    std::cout << "Find Character Test Passed" << std::endl;
}
