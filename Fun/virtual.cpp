#include <iostream>

class Base {
public:
  void Show() const {
    std::cout << "I am the base class!\n";
  }
};

class Child : public Base {
public:
  void Show() const {
    std::cout << "I am the child class!\n";
  }
};

int main() {
  Base a;
  Child b;
  a.Show();
  b.Show();
  return 0;
}
