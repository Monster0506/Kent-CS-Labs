#include <cassert>
#include <iostream>
#include "string.hpp"

int main() {
    {
        String s1("Hello");
        String s2("Hello");
        assert(s1 == s2);
    }
    {
        String s1("Hello");
        String s2("World");
        assert(!(s1 == s2));
    }
    {
        String s1("");
        String s2("");
        assert(s1 == s2);
    }
    std::cout << "Equality Operator Passed" << std::endl;
}
