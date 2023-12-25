#include <iostream>
#include "cow.h"

int main() {
  Cow c1;
  c1.ShowCow();
  Cow c2 = c1;
  c2.ShowCow();
  Cow c3("Moo", "football", 100);
  c3.ShowCow();
  c2 = c3;
  Cow c4 = c3;
  c2.ShowCow();
  c4.ShowCow();
  Cow c5("Mou", "sleeping", 220.2);
  c1 = c5;
  c1.ShowCow();
  c5.ShowCow();
  c5 = c5;
  c5.ShowCow();
  return 0;
}
