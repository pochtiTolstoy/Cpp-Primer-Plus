#include <cstring>
#include <iostream>
#include "strcount.h"

int main() {
  std::string input;
  std::cout << "Enter a line: ";
  while (std::getline(std::cin, input) && input != "") {
    strcount(input);
    std::cout << "Enter next line (empty line to quit): ";
  }
  std::cout << "Bye\n";
  return 0;
}
