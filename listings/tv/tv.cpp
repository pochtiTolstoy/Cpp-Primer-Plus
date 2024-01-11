#include <iostream>
#include "tv.h"

bool Tv::volup() {
  if (volume < MaxVal) {
    ++volume;
    return true;
  }
  return false;
}

bool Tv::voldown() {
  if (volume > MinVal) {
    --volume;
    return true;
  }
  return false;
}

void Tv::chanup() {
  if (channel < maxchannel) ++channel;
  else channel = 1;
}

void Tv::chandown() {
  if (channel > 1) --channel;
  else channel = maxchannel;
}

void Tv::settings() const {
  std::cout << "Tv is " << (state == Off ? "Off" : "On") << '\n';
  if (state == On) {
    std::cout << "Volume setting = " << volume << '\n';
    std::cout << "Channel setting = " << channel << '\n';
    std::cout << "Mode = "
      << (mode == Antenna ? "antenna" : "cable") << '\n';
    std::cout << "Input = "
      << (input == TV ? "TV" : "DVD") << '\n';
  }
}
