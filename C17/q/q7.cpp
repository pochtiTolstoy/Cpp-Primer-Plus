#include <iostream>
#include <iomanip>

int main() {
  char name[20];
  float hourly;
  float hours;
  std::cout << "Enter your name: ";
  std::cin.get(name, 20).get();
  std::cout << "Enter your hourly wages: ";
  std::cin >> hourly;
  std::cout << "Enter number of hours worked: ";
  std::cin >> hours;
  std::cout << std::showpoint << std::fixed << std::right;
  std::cout << "First format:\n";
  std::cout << std::setw(30) << name << ": $" << std::setprecision(2)
    << std::setw(10) << hourly << ":" << std::setprecision(1)
    << std::setw(5) << hours << '\n';
  std::cout << "Second format:\n";
  std::cout << std::left;
  std::cout << std::setw(30) << name << ": $" << std::setprecision(2)
    << std::setw(10) << hourly << ":" << std::setprecision(1)
    << std::setw(5) << hours << '\n';
  return 0;
}
