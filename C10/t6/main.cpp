#include <iostream>
#include "move.h"

int main() {
  Move crds1;
  Move crds2(10.6);
  Move crds3(5.6, 9.6);
  std::cout << "Lets watch our coordinates:\n";
  crds1.showmove();
  crds2.showmove();
  crds3.showmove();

  std::cout << "\nLets add some value for our coords:\n";
  crds1 = crds2.add(crds3);
  crds1.showmove();
  crds2.showmove();
  crds3.showmove();

  std::cout << "\nLets reset our coords:\n";
  crds1.reset(); 
  crds2.reset(100, 100);
  crds3.reset(-1, -2);
  crds1.showmove();
  crds2.showmove();
  crds3.showmove();

  std::cout << "\nBye!\n";
  return 0;
}
