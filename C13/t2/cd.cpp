#include <iostream>
#include <cstring>
#include "cd.h"

// class Cd
Cd::Cd() {
  performer = new char[1];
  performer[0] = '\0';
  label = new char[1];
  label[0] = '\0';
  selections = 0;
  playtime = 0;
}

Cd::Cd(const Cd& c) {
  performer = new char[std::strlen(c.performer) + 1];
  std::strcpy(performer, c.performer); 
  label = new char[std::strlen(c.label) + 1];
  std::strcpy(label, c.label);
  selections = c.selections;
  playtime = c.playtime;
}

Cd::Cd(const char* pf, const char* lb, int sl, double pt) {
  performer = new char[std::strlen(pf) + 1];
  std::strcpy(performer, pf);
  label = new char[std::strlen(lb) + 1];
  std::strcpy(label, lb);
  selections = sl;
  playtime = pt;
}

Cd::~Cd() {
  delete[] performer;
  delete[] label;
}

void Cd::Report() const {
  std::cout << "Performer: " << performer << '\n' 
    << "Label: " << label << '\n'
    << "Selections: " << selections << '\n'
    << "Playtime: " << playtime << "\n\n";
}

Cd& Cd::operator=(const Cd& c) {
  if (this == &c)
    return *this;
  delete[] performer;
  performer = new char[std::strlen(c.performer) + 1];
  std::strcpy(performer, c.performer);
  delete[] label;
  label = new char[std::strlen(c.label) + 1];
  std::strcpy(label, c.label);
  selections = c.selections;
  playtime = c.playtime;
  return *this;
}
