#include <cstring>
#include <iostream>

class F {
private:
  char str_[20];
public:
  F(const char* s = "C++");
  virtual void tell() { std::cout << str_ << '\n'; }
};

F::F(const char* s) {
  std::strncpy(str_, s, 19);
  str_[19] = '\0';
}

class Gloam: private F {
private:
  int glip;
public:
  Gloam(int g = 0, const char* s = "C++");
  Gloam(int g, const F& f);
  void tell() override;
};

Gloam::Gloam(int g, const char* s): F(s), glip(g) {}
Gloam::Gloam(int g, const F& f): F(f), glip(g) {}
void Gloam::tell() {
  std::cout << glip << '\n';
  F::tell();
}

int main() {
  Gloam l(4, "Hello");
  l.tell();
  return 0;
}
