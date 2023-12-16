#include <iostream>
#include <cstring>
#include "golf.h"

static void clear_buffer(void) {
  while (std::cin.get() != '\n')
    continue;
}

static void free_io(void) {
  std::cin.clear();
  clear_buffer();
}

void setgolf(golf& g, const char* name, int hc) {
  strncpy(g.fullname, name, Len);
  g.fullname[Len - 1] = '\0';
  g.handicap = hc;
}

int setgolf(golf& g) {
  std::cout << "Enter a fullname: ";
  if (!std::cin.getline(g.fullname, Len))
    free_io();

  std::cout << "Enter handicap: ";
  while (!(std::cin >> g.handicap)) {
    free_io();
    std::cout << "Please, enter an integer value: ";
  }
  clear_buffer();
  return g.fullname[0] != '\0';
}

void handicap(golf& g, int hc) {
  g.handicap = hc;
}

void showgolf(const golf& g) {
  std::cout << "Golf player:\n";
  std::cout << "Fullname: " << g.fullname << std::endl;
  std::cout << "Handicap: " << g.handicap << std::endl;
}
