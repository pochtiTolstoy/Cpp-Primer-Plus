#include <iostream>
#include <cstring>
#include "cd.h"

// class Cd
Cd::Cd() {
  performer[0] = '\0';
  label[0] = '\0';
  selections = 0;
  playtime = 0;
}

Cd::Cd(const Cd& c) {
  std::strcpy(performer, c.performer); 
  std::strcpy(label, c.label);
  selections = c.selections;
  playtime = c.playtime;
}

Cd::Cd(const char* pf, const char* lb, int sl, double pt) {
  std::strncpy(performer, pf, 50);
  performer[49] = '\0';
  std::strncpy(label, lb, 20);
  label[19] = '\0';
  selections = sl;
  playtime = pt;
}

Cd::~Cd() {}

void Cd::Report() const {
  std::cout << "Performer: " << performer << std::endl
    << "Label: " << label << std::endl
    << "Selections: " << selections << std::endl
    << "Playtime: " << playtime << std::endl;
}

Cd& Cd::operator=(const Cd& c) {
  if (this == &c)
    return *this;
  std::strcpy(performer, c.performer);
  std::strcpy(label, c.label);
  selections = c.selections;
  playtime = c.playtime;
  return *this;
}

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
  std::cout << "Name: " << name << std::endl;
  Cd::Report();
}

Classic& Classic::operator=(const Classic& c) {
  if (this == &c)
    return *this;
  Cd::operator=(c);
  std::strcpy(name, c.name);
  return *this;
}
