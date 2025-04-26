// File: main.cpp
//
// CS 23001 Project 1 bigint
//
// Basics for openning a file for milestone 2
//

#include "bigint.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>

int main() {
  std::ifstream in;       // Define input stream
  in.open("data1-1.txt"); // Open a file
  if (!in) {              // Make sure file opened correctly
    std::cerr << "File not found: data1-1.txt" << std::endl;
    exit(1);
  }

  Bigint x(10);
  Bigint y(2345);
  std::cout << (x + y) << std::endl;
  std::cout << (y[0]) << std::endl;

  in.close();
  return 0;
}
