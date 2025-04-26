#include <cassert>
#include <iostream>
#include "string.hpp"

int main() {
    {
        String s;
        assert(s == "");  // Should be empty
        assert(s.length() == 0);
        assert(s.capacity() == 0);
    }
    std::cout << "Default Constructor Passed" << std::endl;
}
