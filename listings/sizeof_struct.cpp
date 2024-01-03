#include <iostream>
#include <vector>

struct S {
  int a = 1;
  std::vector<int> v; // Также кладётся с адресов кратных восьми
};

int main() {
  std::cout << sizeof(int) << '\n';
  std::cout << sizeof(S) << '\n';
  std::cout << sizeof(std::vector<int>) << '\n';
  return 0;
}
