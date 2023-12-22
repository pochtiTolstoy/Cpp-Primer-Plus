#include <iostream>
#include "compl.h"

void clear_buffer(void);
void free_io(void);

int main() {
  Complex a(3.0, 4.0);
  Complex c;
  std::cout << "Complex a: " << a << std::endl;
  std::cout << "Complex c: " << c << std::endl;
  std::cout << "Enter a complex number (q to quit):\n";
  while (std::cin >> c) {
    std::cout << "c is " << c << std::endl;       
    std::cout << "complex conjugate is " << ~c << '\n';
    std::cout << "a is " << a << std::endl;
    std::cout << "a + c is " << a + c << '\n';
    std::cout << "a - c is " << a - c << '\n';
    std::cout << "a * c is " << a * c << '\n';
    std::cout << "2 * c is " << 2 * c << '\n';
    std::cout << "Enter a complex number (q to quit):\n";
  }
  free_io();
  std::cout << "Done!\n";
  return 0;
}

void clear_buffer(void) {
  while (std::cin.get() != '\n')
    continue;
}

void free_io(void) {
  if (std::cin.fail())
    std::cin.clear();
  clear_buffer;
}
