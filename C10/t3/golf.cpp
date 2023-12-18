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

Golf::Golf() {
  m_fullname[0] = '\0';
  m_handicap = 0;
}

Golf::Golf(const char* name, int hc) {
  strncpy(m_fullname, name, Len);
  m_fullname[Len - 1] = '\0';
  m_handicap = hc;
}

int Golf::setgolf(void) {
  std::cout << "Enter a fullname: ";
  if (!std::cin.getline(m_fullname, Len))
    free_io();

  std::cout << "Enter handicap: ";
  while (!(std::cin >> m_handicap)) {
    free_io();
    std::cout << "Please, enter an integer value: ";
  }
  clear_buffer();
  return m_fullname[0] != '\0';
}

void Golf::handicap(int hc) {
  m_handicap = hc;
}

void Golf::showgolf(void) const {
  std::cout << "Golf player:\n";
  std::cout << "Fullname: " << m_fullname << std::endl;
  std::cout << "Handicap: " << m_handicap << std::endl;
}
