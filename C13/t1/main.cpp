#include <iostream>
#include "cd.h"

void Bravo(const Cd& disk);

int main() {
  Cd c1("Beatles", "Capitol", 14, 35.5); 
  Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
                       "Alfred Brendel", "Philips", 2, 57.17);
  Cd *pcd = &c1; // B -> B
  std::cout << "Using object directly:\n";
  c1.Report();
  c2.Report();
  std::cout << "Using type cd* pointer to objects:\n";
  pcd->Report();
  pcd = &c2; // B -> P
  pcd->Report(); // Динамическое связывание
  std::cout << "Calling a function with a Cd reference argument:\n";
  Bravo(c1); // B -> B
  Bravo(c2); // B -> P
  std::cout << "Testing assignment:\n";
  Classic copy;
  copy = c2; // P = P
  copy.Report();
  return 0;
}

void Bravo(const Cd& disk) {
  disk.Report();
}
