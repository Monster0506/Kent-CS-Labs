#include "string.hpp"
#include <iostream>
#include <vector>
#include <cassert>



int main() {
    String s1("abc ef gh");
    std::vector<String> result1 = s1.split(' ');
    assert(result1.size() == 3);
    assert(result1[0] == "abc");
    assert(result1[1] == "ef");
    assert(result1[2] == "gh");

    String s2("-a--b-");
    std::vector<String> result2 = s2.split('-');
    assert(result2.size() == 5);
    assert(result2[0] == "");
    assert(result2[1] == "a");
    assert(result2[2] == "");
    assert(result2[3] == "b");
    assert(result2[4] == "");

    String s3("singleword");
    std::vector<String> result3 = s3.split(',');
    assert(result3.size() == 1);
    assert(result3[0] == "singleword");

    String s4("");
    std::vector<String> result4 = s4.split(' ');
    assert(result4.size() == 1);
    assert(result4[0] == "");

    std::cout << "Split Test Passed.\n";
    return 0;
}
