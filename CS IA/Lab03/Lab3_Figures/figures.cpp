#include <iostream>

int main() {
  char character;
  int size;

  std::cout << "Input figure size: ";
  std::cin >> size;
  std::cout << "Input paint character: ";
  std::cin >> character;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      std::cout << character;
    }
    std::cout << std::endl;
  }

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
