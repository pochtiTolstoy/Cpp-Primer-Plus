#include <iostream>

class A {
private:
  int num;
public:
  A(int n = 0) { num = n; }
  friend void f(A& a);
};

void f(A& a) {
  std::cout << "Wow, i am a friend function!\n";
  std::cout << "This is num value from the class: " << a.num << std::endl;
  a.num = 5;
  std::cout << "This is new value for num: " << a.num << std::endl;
}

int main() {
  //const friend function and non-const friend function
  A a;
  f(a);
  return 0;
}
