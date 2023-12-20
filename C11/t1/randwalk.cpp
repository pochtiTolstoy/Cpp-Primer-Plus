#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include "vect.h"

int main() {
  using VECTOR::Vector;
  srand(time(0));
  double direction;
  Vector step;
  Vector result(0.0, 0.0);
  unsigned long steps = 0;
  double target;
  double dstep;
  double val;
  std::ofstream fp;
  fp.open("data.txt");
  if (!fp.is_open()) {
    std::cout << "File is not open.\n";
    exit(EXIT_FAILURE);
  }
  std::cout << "Enter target distance (q to quit): ";
  while (std::cin >> target) {
    std::cout << "Enter step length: ";
    if (!(std::cin >> dstep))
      break;
    fp << "Target Distance: " << target << ", Step Size: " << dstep << std::endl;
    fp << steps << ": " << result << std::endl;
    while (result.magval() < target) {
      direction = rand() % 360;
      step.reset(dstep, direction, Vector::POL);
      result = result + step;
      ++steps;
      fp << steps << ": " << result << std::endl;
    }
    fp << "After " << steps << " steps, the subject "
              << "has the following location:\n";
    fp << result << std::endl;
    result.polar_mode();
    fp << " or\n" << result << std::endl;
    fp << "Average outward distance per step = "
              << result.magval() / steps << std::endl;
    fp << std::endl;
    steps = 0;
    result.reset(0.0, 0.0);
    std::cout << "Enter target distance (q to quit): ";
  }
  std::cout << "Bye!\n";
  std::cin.clear();
  while (std::cin.get() != '\n')
    continue;
  fp.close();
  return 0;
}
