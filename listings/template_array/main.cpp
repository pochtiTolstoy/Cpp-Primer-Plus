#include <iostream>
#include "array.h"

int main() {
  Array<int, 10> sums;
  Array<double, 10> aves;
  Array<Array<int, 5>, 10> twodee;
  for (int i = 0; i < 10; ++i) {
    sums[i] = 0;
    for (int j = 0; j < 5; ++j) {
      twodee[i][j] = (i + 1) * (j + 1);
      sums[i] += twodee[i][j];
    }
    aves[i] = static_cast<double>(sums[i]) / 10;
  }
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 5; ++j) {
      std::cout.width(2);
      std::cout << twodee[i][j] << ' ';
    }
    std::cout << ": sum = ";
    std::cout.width(3);
    std::cout << sums[i] << ", average = " << aves[i] << '\n';
  }
  Array<Array<int, 10>, 3> test(sums);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 10; ++j) {
      std::cout << test[i][j] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << "Done.\n";
  return 0;
}
