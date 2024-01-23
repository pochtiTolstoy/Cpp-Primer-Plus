#include <iostream>
#include <cmath>

int main() {
  std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
  std::cout.setf(std::ios_base::showpos);
  std::cout.setf(std::ios_base::showpoint);
  std::cout.precision(3);

  std::ios_base::fmtflags old = std::cout.setf(
    std::ios_base::scientific, std::ios_base::floatfield
  );
  std::cout << "Left Justification:\n";
  long n;
  for (n = 1; n <= 41; n += 10) {
    std::cout.width(4);
    std::cout << n << "|";
    std::cout.width(12);
    std::cout << sqrt(static_cast<double>(n)) << "|\n";
  }

  std::cout.setf(std::ios_base::internal, std::ios_base::adjustfield);
  std::cout.setf(old, std::ios_base::floatfield);
  std::cout << "Internal Justification:\n";
  for (n = 1; n <= 41; n += 10) {
    std::cout.width(4);
    std::cout << n << "|";
    std::cout.width(12);
    std::cout << sqrt(static_cast<double>(n)) << "|\n";
  }

  std::cout.setf(std::ios_base::right, std::ios_base::adjustfield);
  std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
  std::cout << "Right justification:\n";
  for (n = 1; n <= 41; n += 10) {
    std::cout.width(4);
    std::cout << n << "|";
    std::cout.width(12);
    std::cout << sqrt(static_cast<double>(n)) << "|\n";
  }

  return 0;
}
