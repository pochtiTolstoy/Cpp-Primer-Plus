#include <iostream>
#include "plorg.h"

int main() {
  Plorg p1; //defaul constr
  Plorg p2("Apple");
  std::cout << "Show them!\n";
  p1.show_plorg();
  p2.show_plorg();
  std::cout << "Lets add them points:\n";
  p1.change_CI(100);
  p2.change_CI(200);
  p1.show_plorg();
  p2.show_plorg();
  std::cout << "End.\n";
  return 0;
}
