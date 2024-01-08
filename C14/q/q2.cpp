#include <cstring>
#include <iostream>

class Frabjous {
private:
  char fab[20];
public:
  Frabjous(const char* s = "C++");
  virtual void tell() { std::cout << fab; }
};

Frabjous::Frabjous(const char* s) {
  std::strncpy(fab, s, 19);
  fab[19] = '\0';
}

class Gloam {
private:
  int glip;
  Frabjous fb;
public:
  Gloam(int g = 0, const char* s = "C++");
  Gloam(int g, const Frabjous& f);
  void tell();
};

Gloam::Gloam(int g, const char* s): glip(g), fb(s) {}
Gloam::Gloam(int g, const Frabjous& f): glip(g), fb(f) {}
void Gloam::tell() {
  std::cout << "Glip: " << glip << '\n'
            << "Frabjous: ";
  fb.tell();
  std::cout << '\n';
}

int main() {
  Gloam lm;
  lm.tell();
  return 0;
}
