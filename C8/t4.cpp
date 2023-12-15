#include <iostream>
#include <cstring> // strlen(), strcpy()

struct stringy {
  char* str;
  int ct;    // len of string without '\0'
};

void set(stringy&, const char*); // new
void show(const stringy&, int n = 1);
void show(const char*, int n = 1);

int main() {
  stringy beany;
  char testing[] = "Reality isn't what it used to be.";

  set(beany, testing);

  show(beany);
  show(beany, 2);
  testing[0] = 'D';
  testing[1] = 'u';
  show(testing);
  show(testing, 3);
  show("Done!");

  delete[] beany.str;

  return 0;
}

void set(stringy& target, const char* source) {
  target.ct = strlen(source);
  target.str = new char[target.ct + 1];
  strcpy(target.str, source);
  target.str[target.ct] = '\0';
}

void show(const stringy& obj, int n) {
  for (int i = 0; i < n; ++i)
    std::cout << obj.str << std::endl; 
}

void show(const char* str, int n) {
  for (int i = 0; i < n; ++i)
    std::cout << str << std::endl; 
}
