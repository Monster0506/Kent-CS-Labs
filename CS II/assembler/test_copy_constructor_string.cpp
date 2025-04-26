#include <cassert>
#include <iostream>
#include "stack.hpp"
#include "../string/string.hpp"

int main() {
    stack<String> s1;
    s1.push("42");
    s1.push("99");
    
    stack<String> s2(s1);  
    
    assert(s2.top() == "99");
    assert(s2.pop() == "99");
    assert(s2.top() == "42");
    assert(s2.pop() == "42");
    assert(s2.empty());

    std::cout << "Done testing copy constructor string." << std::endl;
    return 0;
}

