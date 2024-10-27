#include "figures.hpp"
#include <iostream>

int main() {
  int choice;
  int size;
  char character, choice2;
  do {
    std::cout << "Enter size: ";
    std::cin >> size;
    std::cout << "Input paint character: ";
    std::cin >> character;
    std::cout << "1. Square\n2. Slash\n3. X\n";
    std::cout << "Enter a choice: ";
    std::cin >> choice;
    if (choice < 1 || choice > 3) {
      break;
    }
    switch (choice) {
    case 1:
      std::cout << "filled/hollow [f/h]: ";
      std::cin >> choice2;
      if (choice2 == 'f') {
        filledSquare(size, character);
        break;
      }
      hollowSquare(size, character);
      break;
    case 2:
      std::cout << "forward/back [f/b]: ";
      std::cin >> choice2;
      if (choice2 == 'f') {
        slash(size, character);
        break;
      }
      backslash(size, character);
      break;
    case 3:
      x(size, character);
      break;
    }
  } while (true);
}
