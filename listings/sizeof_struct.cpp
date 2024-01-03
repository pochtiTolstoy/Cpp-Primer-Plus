#include <iostream>
#include <vector>

struct S {
  int n = 1;
  int a = 10;
  std::vector<int> v;
};

int main() {
  std::cout << sizeof(S) << '\n';
  std::cout << sizeof(std::vector<int>) << '\n';
  return 0;
}
