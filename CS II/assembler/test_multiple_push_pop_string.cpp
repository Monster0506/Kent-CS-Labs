#include <cassert>
#include <iostream>
#include "stack.hpp"
#include "../string/string.hpp"

int main() {
    stack<String> s;
    s.push("1");
    s.push("2");
    s.push("3");
    
    assert(s.top() == "3");
    assert(s.pop() == "3");
    assert(s.top() == "2");
    assert(s.pop() == "2");
    assert(s.top() == "1");
    assert(s.pop() == "1");
    assert(s.empty());

    std::cout << "Done testing multiple push/pop operations string." << std::endl;
    return 0;
}

