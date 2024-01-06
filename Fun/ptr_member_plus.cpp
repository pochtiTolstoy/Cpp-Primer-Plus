#include <iostream>

struct S {
  int x;
  double d;
  double f;
  void fun(char c) { std::cout << "Hello, " << c << '\n'; }
};

void func(char c) { std::cout << "Hello, " << c << '\n'; }

int main() {
  int S::* pt = &S::x;
  void (S::* pf)(char) = &S::fun;
  void (*pff)(char) = func;
  S s{2, 3.3, 4.4};
  std::cout << "result: " << s.*pt << '\n';
  (s.*pf)('a');
  (*pff)('a');
  return 0;
}
