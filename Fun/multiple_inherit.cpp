#include <iostream>

class Mother {
private:
  int x;
};

class Father {
private:
  int y;
};

class Son: public Mother, public Father {
private:
  int z;
};

int main() {
  std::cout << sizeof(Son) << '\n';
  Son s;
  std::cout << "Son address: " << &s << '\n';
  Father* pf1 = &s;
  Mother* pf2 = &s;
  std::cout << "Father address: " << pf1 << '\n';
  std::cout << "Mother address: " << pf2 << '\n';
  return 0;
}
