#include <cassert>
#include <iostream>
#include "stack.hpp"

int main() {
    stack<int> s;
    s.push(10);
    assert(!s.empty());
    assert(s.top() == 10);
    assert(s.pop() == 10);
    assert(s.empty());

    std::cout << "Done testing push and pop." << std::endl;
    return 0;
}

