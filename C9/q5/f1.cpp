#include <iostream>
#include "fun.h"

int main() {
  std::cout << f_int::average(5, 4) << std::endl;
  std::cout << f_double::average(5, 4) << std::endl;
  return 0;
}
