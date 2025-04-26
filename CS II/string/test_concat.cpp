#include <cassert>
#include <iostream>
#include "string.hpp"

int main() {
    {
        String s1("Hello");
        String s2(" World");
        s1 += s2;
        assert(s1 == "Hello World");
    }
    {
        String s1("Hello");
        assert((s1 + " World") == "Hello World");
    }
    {
        String s1("");
        String s2("Test");
        assert((s1 + s2) == "Test");
    }
    std::cout << "Concatenation Operator Passed" << std::endl;
}
