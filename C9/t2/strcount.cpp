#include <iostream>
#include "strcount.h"
void strcount(const std::string& str) {
  static int total = 0;
  int count = str.size();
  std::cout << "\"" << str << "\" contains ";
  total += count;
  std::cout << count << " characters\n";
  std::cout << total << " characters total\n";
}
