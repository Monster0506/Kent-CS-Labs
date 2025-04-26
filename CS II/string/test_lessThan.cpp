#include <cassert>
#include <iostream>
#include "string.hpp"

int main() {
    {
        String s1("Apple");
        String s2("Banana");
        assert(s1 < s2);
    }
    {
        String s1("aaa");
        String s2("aaaa");
        assert(s1 < s2);
    }
    {
        String s1("Zebra");
        String s2("apple");
        assert(s1 < s2);
    }
    std::cout << "Less Than Operator Passed" << std::endl;
}
