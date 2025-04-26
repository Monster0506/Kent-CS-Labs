#include <cassert>
#include <iostream>
#include "stack.hpp"

int main() {
    stack<int> s1, s2;
    s1.push(3);
    s1.push(6);
    
    s2.push(10);
    
    s1.swap(s2);

    assert(s1.top() == 10);
    assert(s1.pop() == 10);
    assert(s1.empty());

    assert(s2.top() == 6);
    assert(s2.pop() == 6);
    assert(s2.top() == 3);
    assert(s2.pop() == 3);
    assert(s2.empty());

    std::cout << "Done testing swap function." << std::endl;
    return 0;
}

