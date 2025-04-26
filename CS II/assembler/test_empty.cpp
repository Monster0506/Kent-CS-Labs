#include <cassert>
#include "stack.hpp"
#include <iostream>

int main() {
    stack<int> s;
    assert(s.empty());
    s.push(1);
    assert(!s.empty());
    std::cout<<"Done testing empty"<<std::endl;
    return 0;
}

