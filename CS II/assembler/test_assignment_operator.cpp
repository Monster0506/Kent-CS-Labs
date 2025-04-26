#include <cassert>
#include <iostream>
#include "stack.hpp"

int main() {
    stack<int> s1;
    s1.push(5);
    s1.push(15);

    stack<int> s2;
    s2 = s1; 

    assert(s2.top() == 15);
    assert(s2.pop() == 15);
    assert(s2.top() == 5);
    assert(s2.pop() == 5);
    assert(s2.empty());

    std::cout << "Done testing assignment operator." << std::endl;
    return 0;
}

