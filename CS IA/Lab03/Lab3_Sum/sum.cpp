#include <iostream>
#include <ostream>

int main() {
  std::cout << "Enter a sequence of integers (0 to end): ";
  int num = -1;
  int sum = 0;

  do {
    std::cout << "Enter a number: ";
    std::cout << num << std::endl;
    if (num > 0) {
      sum += num;
    }

  } while (num != 0);
  std::cout << "Sum: " << sum << std::endl;
}
