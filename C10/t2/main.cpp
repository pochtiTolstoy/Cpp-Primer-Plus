#include <iostream>
#include "person.h"

int main() {
  Person one; 
  Person two("Apple");
  Person three("Dimwiddy", "Sam");

  one.Show();
  one.FormalShow();
  std::cout << '\n';

  two.Show();
  two.FormalShow();
  std::cout << '\n';

  three.Show();
  three.FormalShow();
  std::cout << '\n';

  return 0;
}
