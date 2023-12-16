#include <iostream>
#include "golf.h"

const int SIZE = 5; // Внутреннее связывание

int main() {
  golf players[SIZE];
  int items;
  for (items = 0; items < SIZE; ++items) {
    std::cout << "Enter player #" << items + 1 << ":\n";
    if (!setgolf(players[items]))
      break;
  }
  std::cout << '\n';
  
  for (int i = 0; i < items; ++i)
    showgolf(players[i]);
  if (items == 0)
    std::cout << "There are no players in database!\n";

  return 0;
}
