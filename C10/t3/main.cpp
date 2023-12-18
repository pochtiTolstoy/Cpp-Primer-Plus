#include <iostream>
#include "golf.h"

const int SIZE = 5; // Внутреннее связывание

int main() {
  Golf players[SIZE];
  int items;
  for (items = 0; items < SIZE; ++items) {
    std::cout << "Enter player #" << items + 1 << ":\n";
    if (!players[items].setgolf())
      break;
  }
  std::cout << '\n';
  
  for (int i = 0; i < items; ++i)
    players[i].showgolf();
  if (items == 0)
    std::cout << "There are no players in database!\n";

  return 0;
}
