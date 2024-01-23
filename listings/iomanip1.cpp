#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
  std::cout << std::fixed << std::right;
  std::cout << std::setw(6) << "N" << std::setw(14) << "square root:"
    << std::setw(15) << "fourth root:\n";
  double root;
  for (int n = 10; n <= 100; n += 10) {
    root = sqrt(static_cast<double>(n));
    std::cout << std::setw(6) << std::setfill('.') << n << std::setfill(' ')
      << std::setw(13) << std::setprecision(3) << root
      << std::setw(14) << std::setprecision(4) << sqrt(root)
      << '\n';
  }
  return 0;
}
