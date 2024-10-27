#include "figures.hpp"
#include <iostream>

void filledSquare(int size, char character) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      std::cout << character;
    }
    std::cout << std::endl;
  }
}

void slash(int size, char character) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i == j) {
        std::cout << character;
      } else {
        std::cout << ' ';
      }
    }
    std::cout << std::endl;
  }
}
void backslash(int size, char character) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i == (size - 1 - j)) {
        std::cout << character;
      } else {
        std::cout << ' ';
      }
    }
    std::cout << std::endl;
  }
}

void hollowSquare(int size, char character) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i == 0) {
        std::cout << character;
      } else if (i == size - 1) {
        std::cout << character;
      } else if (j == 0) {
        std::cout << character;
      } else if (j == size - 1) {
        std::cout << character;
      } else {
        std::cout << ' ';
      }
    }
    std::cout << std::endl;
  }
}

void x(int size, char character) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i == j) {
        std::cout << character;
      } else if (i == size - 1 - j) {
        std::cout << character;
      } else {
        std::cout << ' ';
      }
    }
    std::cout << std::endl;
  }
}
