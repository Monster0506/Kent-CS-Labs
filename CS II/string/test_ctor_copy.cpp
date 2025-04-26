#include "string.hpp"
#include <iostream>
#include <cassert>

int main()
{
    String original("Hello");
    String copy(original);

    assert(copy == original);                       
    assert(copy.length() == original.length());     
    assert(copy.capacity() == original.capacity()); 

    std::cout << "Copy constructor test passed.\n";
    return 0;
}
