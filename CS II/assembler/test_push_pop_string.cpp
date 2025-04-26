#include <cassert>
#include <iostream>
#include "stack.hpp"
#include "../string/string.hpp"

int main() {
    stack<String> s;
    s.push("10");
    assert(!s.empty());
    assert(s.top() == "10");
    assert(s.pop() == "10");
    assert(s.empty());

    std::cout << "Done testing push and pop string." << std::endl;
    return 0;
}

