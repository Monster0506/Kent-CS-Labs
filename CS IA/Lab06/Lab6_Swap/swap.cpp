#include <iostream>

using std::cin;
using std::cout;
using std::endl;
void swap(int &left, int &right);

int main() {

  // inputs the numbers
  cout << "Enter three numbers: ";
  int x, y, z;
  cin >> x >> y >> z;

  int tmp;

  // orders x and y
  if (x > y) {
    swap(x, y);
  }

  // orders y and z
  if (y > z) {
    swap(y, z);
  }
  // orders x and y
  if (x > y) {
    swap(x, y);
  }

  // outputs the sorted numbers
  cout << "The sorted numbers are: ";
  cout << x << " " << y << " " << z << endl;
}
void swap(int &left, int &right) {
  const int tmp = left;
  left = right;
  right = tmp;
}
