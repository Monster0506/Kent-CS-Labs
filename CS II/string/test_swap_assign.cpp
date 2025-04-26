#include "string.hpp"
#include <iostream>
#include <cassert>

int main()
{
    {
        String a("First");
        String b("Second");

        a.swap(b);

        assert(a == "Second");
        assert(b == "First");

        std::cout << "Swap Test Passed.\n";
    }
    {
        String a("Hello");
        String b("World");

        b = a;

        assert(b == "Hello");
        assert(b.length() == a.length());

        std::cout << "Assignment Operator Test Passed.\n";
    }
    return 0;
}
