#include <cassert>
#include <iostream>
#include "stack.hpp"
#include "../string/string.hpp"

int main() {
    stack<String> s1;
    s1.push("1");
    s1.push("15");

    stack<String> s2;
    s2 = s1; 

    assert(s2.top() == "15");
    assert(s2.pop() == "15");
    assert(s2.top() == "1");
    assert(s2.pop() == "1");
    assert(s2.empty());

    std::cout << "Done testing assignment operator string" << std::endl;
    return 0;
}

