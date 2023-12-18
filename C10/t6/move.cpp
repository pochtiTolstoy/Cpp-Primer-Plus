#include <iostream>
#include "move.h"

Move::Move(double a, double b) {
  x = a;
  y = b;
}

void Move::showmove(void) const {
  std::cout << "Show move object:\n"
            << "x = " << x << ", y = " << y << std::endl;
}

Move Move::add(const Move& m) const {
  Move temp;
  temp.x = x + m.x;
  temp.y = y + m.y;
  return temp; // return with a copy to temporary storage
}

void Move::reset(double a, double b) {
  x = a;
  y = b;
}
