#include <iostream>
#include "stonewt.h"

int main() {
  Stonewt obj1(10, 3.0, Stonewt::STN);
  Stonewt obj2(10); //LBS
  std::cout << obj2 << std::endl;
  obj1 = obj1 + obj2;
  obj1 = obj1 + 1;
  std::cout << obj1 << std::endl;
  

  return 0;
}
