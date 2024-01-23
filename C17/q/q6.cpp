#include <iostream>
#include <iomanip>

int main() {
  std::cout << "Enter integer number: ";
  int num;
  std::cin >> num;
  std::cout << std::setw(15) << "base ten" << std::setw(15)
    << "base sixteen" << std::setw(15) << " base eight" << '\n';
  std::cout << std::showbase;
  std::cout << std::setw(15) << num << std::hex << std::setw(15) << num
    << std::oct << std::setw(15) << num << '\n';
  return 0;
}
