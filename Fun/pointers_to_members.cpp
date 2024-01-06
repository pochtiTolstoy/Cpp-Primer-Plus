#include <iostream>

struct S {
  int x;
  double d;
  void f(char c) {}
};

int main() {
  int S::* p = &S::x;
  S s{5, 1.1};
  std::cout << s.*p << '\n';
  return 0;
}
