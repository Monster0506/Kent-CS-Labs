#include <iostream>
void assign(int chosen[], int size);
bool check(int chosen[], int size, int num);
void draw(int chosen[], int size);
int entry();
void printOut(int chosen[], int size);

int main() {
  const int SIZE = 10;
  int chosen[SIZE];
  assign(chosen, SIZE);
  draw(chosen, SIZE);
  int user;
  for (int i = 0; i < 5; i++) {
    user = entry();
    if (check(chosen, SIZE, user)) {
      std::cout << "You Win!" << std::endl;
      break;
    }
  }
  printOut(chosen, SIZE);
}
void assign(int chosen[], int size) {
  for (int i = 0; i < size; i++) {
    chosen[i] = -1;
  }
}
bool check(int chosen[], int size, int num) {
  for (int i = 0; i < size; i++) {
    if (chosen[i] == num) {
      return true;
    }
  }
  return false;
}
void draw(int chosen[], int size) {
  int num;
  srand(time(nullptr));
  for (int i = 0; i < size; i++) {
    do {
      num = rand() % 100;
    } while (check(chosen, size, num));
    chosen[i] = num;
  }
}

int entry() {
  int result;
  std::cout << "Enter a number between 0 and 99: ";
  std::cin >> result;
  return result;
}

void printOut(int chosen[], int size) {
  for (int i = 0; i < size; i++) {
    std::cout << chosen[i] << " ";
  }
  std::cout << std::endl;
}
