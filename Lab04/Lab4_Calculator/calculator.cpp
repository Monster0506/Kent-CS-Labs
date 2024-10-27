#include <cmath>
#include <iostream>

int main() {
  int choice = -1;
  int num;
  std::cout << "1. Absolute Value\n2. Square Root\n3. Cube Root\n4. Power\n";
  do {

    std::cout << "Enter a choice: ";
    std::cin >> choice;
    switch (choice) {

    case 1:
      std::cout << "Enter a number: ";
      std::cin >> num;
      std::cout << "The absolute value of " << num << " is " << abs(num)
                << std::endl;
      break;
    case 2:
      std::cout << "Enter a number: ";
      std::cin >> num;
      std::cout << "The square root of " << num << " is " << sqrt(num)
                << std::endl;
      break;
    case 3:
      std::cout << "Enter a number: ";
      std::cin >> num;
      std::cout << "The cube root of " << num << " is " << cbrt(num)
                << std::endl;
      break;
    case 4:
      std::cout << "Enter a number: ";
      std::cin >> num;
      int power;
      std::cout << "Ener a power: ";
      std::cin >> power;
      std::cout << num << " to the power of " << power << " is "
                << pow(num, power) << std::endl;
    }
  } while (choice >= 1 && choice <= 4);
}
