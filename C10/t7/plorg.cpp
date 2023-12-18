#include <iostream>
#include <cstring>
#include "plorg.h"

Plorg::Plorg(const char* str) {
  CI = 50;  
  strncpy(name, str, 20);
  name[19] = '\0';
}

void Plorg::change_CI(int num) {
  CI += num;
}

void Plorg::show_plorg(void) const {
  std::cout << "Show plorg:" << std::endl
            << "Name: " << name << std::endl
            << "CI: " << CI << std::endl;
}
