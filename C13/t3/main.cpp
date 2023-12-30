#include <iostream>
#include "dma.h"

int main() {
  baseDMA shirt("P", 7);
  lacksDMA balloon("red", "bimpo", 4);
  hasDMA map("Mer", "BUF", 6);

  std::cout << "Displaying baseDMA:\n";
  std::cout << shirt << '\n';

  std::cout << "Displaying lacksDMA:\n";
  std::cout << balloon << '\n';

  std::cout << "Displaying hasDMA:\n";
  std::cout << map << '\n';

  lacksDMA balloon2(balloon);
  std::cout << "Result of lacksDMA copy constructor:\n";
  std::cout << balloon2 << std::endl;

  hasDMA map2;
  map2 = map;
  std::cout << "Result of hasDMA assignment operator:\n";
  std::cout << map2 << std::endl;

  return 0;
}
