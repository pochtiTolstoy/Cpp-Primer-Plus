#include <iostream>
#include "person.h"

Person::Person(const std::string& ln, const char* fn) {
  lname = ln;
  strncpy(fname, fn, LIMIT);
  fname[LIMIT - 1] = '\0';
}

void Person::Show() const {
  std::cout << "Full name: " << fname << ' ' << lname << std::endl; 
}

void Person::FormalShow() const {
  std::cout << "Formal full name: " << lname << ", " << fname << std::endl; 
}
