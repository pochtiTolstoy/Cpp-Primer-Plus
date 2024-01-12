#include <iostream>
#include "tv.h"

int main() {
  Tv s42;
  std::cout << "Initial settings for 42\" TV:\n";
  s42.settings();
  s42.onoff();
  s42.chanup();
  std::cout << "\nAdjusted settings for 42\" TV:\n";

  Remote grey;
  grey.set_chan(s42, 10);
  grey.volup(s42);
  grey.volup(s42);
  std::cout << "\nAdjusted settings for 42\" TV:\n";
  s42.settings();

  Tv s58(Tv::On);
  s58.set_mode();
  grey.set_chan(s58, 28);
  std::cout << "\nAdjusted settings for 58\" TV:\n";
  s58.settings();

  std::cout << "Remote info:\n";
  grey.show_remote_mode();
  Tv s66;
  s66.settings();
  s66.change_remote_mode(grey);
  std::cout << "Remote info:\n";
  grey.show_remote_mode();

  std::cout << "Tv s66:\n";
  s66.settings();
  s66.change_remote_mode(grey);
  grey.onoff(s66);
  s66.settings();
  s66.change_remote_mode(grey);
  std::cout << "Remote info:\n";
  grey.show_remote_mode();
  s66.change_remote_mode(grey);
  std::cout << "Remote info:\n";
  grey.show_remote_mode();

  std::cout << "End of the programm\n";
  return 0;
}
