#include <iostream>

int main() {
  int ct = 0;
  while (std::cin.peek() != '$') {
    std::cin.get();
    ++ct;
  }
  std::cout << ct;
  return 0;
}
