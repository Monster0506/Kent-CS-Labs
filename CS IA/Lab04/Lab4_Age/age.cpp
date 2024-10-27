#include <iostream>

int main() {
  int age;
  int guess = 0;
  int year = 1000;
  srand(time(nullptr));
  age = rand() % 100 + 1;

  while (true) {
    std::cout << "Year " << year;
    std::cout << ": Hello, fair maiden. I am a fearsome dragon. How old am I? ";
    std::cin >> guess;
    if (guess == age) {
      break;
    } else if (guess < age) {
      std::cout << "Wrong, I am older. No handsome prince for you. See you in "
                   "five years."
                << std::endl;
    } else {
      std::cout << "Wrong, I am younger. No handsome prince for you. See you "
                   "in five years."
                << std::endl;
    }

    year += 5;
    age += 5;
  }
  std::cout
      << "You got it! Here is the handsome prince. Live happily ever after!"
      << std::endl;
}
