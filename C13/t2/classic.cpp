#include <iostream>
#include <cstring>
#include "classic.h"

// class Classic
Classic::Classic() : Cd() {
  name = new char[1];
  name[0] = '\0'; 
}

Classic::Classic(const Classic& c) : Cd(c) {
  name = new char[std::strlen(c.name) + 1];
  std::strcpy(name, c.name);
}

Classic::Classic(
  const char* nm,
  const char* pf,
  const char* lb,
  int sl,
  double pt
) : Cd(pf, lb, sl, pt) {
  name = new char[std::strlen(nm) + 1];
  std::strcpy(name, nm); 
}

Classic::~Classic() {
  delete[] name;
} // Automaticly calls base destructor

void Classic::Report() const {
  std::cout << "Name: " << name << '\n';
  Cd::Report();
}

Classic& Classic::operator=(const Classic& c) {
  if (this == &c)
    return *this;
  Cd::operator=(c);
  delete[] name;
  name = new char[std::strlen(c.name) + 1];
  std::strcpy(name, c.name);
  return *this;
}
