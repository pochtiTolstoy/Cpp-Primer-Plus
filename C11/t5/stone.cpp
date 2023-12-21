#include <iostream>
#include "stonewt.h"

void display(const Stonewt& st, int n);

int main() {
  Stonewt obj(10, 8.0);
  obj.lbs_mode();
  std::cout << obj << std::endl;
  obj = obj * 2;
  std::cout << obj << std::endl;

  return 0;
}

void display(const Stonewt& st, int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << "Wow! ";
    std::cout << st << std::endl;
  }
}
