#include <iostream>
#include <new>
#include <cstdlib>

struct Big {
  double stuff[200000];
};

int main() {
  Big* pb;
  try {
    pb = new Big[10000];
    std::cout << "OK\n";
  } catch (std::bad_alloc& ba) {
    std::cout << ba.what() << '\n';
    exit(EXIT_FAILURE);
  }
  std::cout << "Allocated\n";
  pb[0].stuff[0] = 4;
  std::cout << pb[0].stuff[0] << '\n';
  delete[] pb;
  return 0;
}
