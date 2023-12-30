#include <iostream>
#include <cstring>
#include "classic.h"

// class Classic
Classic::Classic() : Cd() {
  name[0] = '\0'; 
}

Classic::Classic(const Classic& c) : Cd(c) {
  std::strcpy(name, c.name);
}

Classic::Classic(
  const char* nm,
  const char* pf,
  const char* lb,
  int sl,
  double pt
) : Cd(pf, lb, sl, pt) {
  std::strncpy(name, nm, 65); 
  name[64] = '\0';
}

Classic::~Classic() {} // Automaticly calls base destructor

void Classic::Report() const {
  std::cout << "Name: " << name << '\n';
  Cd::Report();
}

Classic& Classic::operator=(const Classic& c) {
  if (this == &c)
    return *this;
  Cd::operator=(c);
  std::strcpy(name, c.name);
  return *this;
}
