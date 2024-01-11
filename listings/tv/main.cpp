#include <iostream>
#include "tv.h"

int main() {
  Tv s42;
  std::cout << "Initial settings for 42\" TV:\n";
  s42.settings();
  s42.onoff();
  s42.chanup();
  std::cout << "\nAdjusted setttings for 42\" TV:\n";

  s42.settings();
  Remote grey;
  grey.set_chan(s42, 10);
  grey.volup(s42);
  grey.volup(s42);
  std::cout << "\n42\" settings after using remote:\n";

  s42.settings();
  Tv s58(Tv::On);
  s58.set_mode();
  grey.set_chan(s58, 28);
  std::cout << "\n58\" settibgs:\n";
  s58.settings();
  return 0;
}
