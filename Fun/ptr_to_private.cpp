#include <iostream>

class A;

void change_member(A&, int A::*);

class A {
private:
  int x = 0;
  double d = 0.0;
public:
  void f(void);
  int get_x(void) const { return x; }
};

void A::f(void) {
  std::cout << "calls f function\n";
  int A::* p_int = &A::x;
  ::change_member(*this, p_int);
}

int main() {
  A a;
  std::cout << a.get_x() << '\n';
  a.f();
  std::cout << a.get_x() << '\n';
  return 0;
}

void change_member(A& a, int A::* p_int) {
  
  // Incorrect (x is private)
  //a.x = 15;
  
  // Correct (x is private, but we have pointer):
  a.*p_int = 10;
}
