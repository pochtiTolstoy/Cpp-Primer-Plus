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
  std::cout << "Performer: " << performer << '\n' 
    << "Label: " << label << '\n'
    << "Selections: " << selections << '\n'
    << "Playtime: " << playtime << "\n\n";
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
