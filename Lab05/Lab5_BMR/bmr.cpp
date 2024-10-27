#include <iostream>

const int CALORIES_PER_COOKIE = 150;
double bmrWomen(double lbs, double in, double yrs);
double bmrMen(double lbs, double in, double yrs);

int main() {
  double weight, feet, inches, height, years, bmr;
  char gender;

  std::cout << "Enter your gender (m/f): ";
  std::cin >> gender;
  std::cout << "Enter your height (foot part): ";
  std::cin >> feet;
  std::cout << "Enter your height (inch part): ";
  std::cin >> inches;
  height = 12 * feet + inches;
  std::cout << "Enter your weight: ";
  std::cin >> weight;
  if (gender == 'm') {
    bmr = bmrMen(weight, height, years);
  } else {
    bmr = bmrWomen(weight, height, years);
  }

  std::cout << "BMR: " << bmr << " Consumable cookies: "
            << static_cast<int>(bmr / CALORIES_PER_COOKIE) << std::endl;
}

double bmrWomen(double lbs, double in, double yrs) {
  return 655 + (4.3 * lbs) + (4.7 * in) - (4.7 * yrs);
}
double bmrMen(double lbs, double in, double yrs) {
  return 66 + (6.3 * lbs) + (12.9 * in) - (6.8 * yrs);
}
