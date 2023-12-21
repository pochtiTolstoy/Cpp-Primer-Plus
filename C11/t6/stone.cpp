#include <iostream>
#include "stonewt.h"

void free_io(void);
void clear_buffer(void);

int main() {
  const int SIZE = 6;
  Stonewt data[SIZE] = {
    Stonewt(10.0, Stonewt::STN),
    Stonewt(14.0, Stonewt::STN),
    Stonewt(23.0, Stonewt::STN)
  };

//READ VALUES
  double lbs;
  for (int i = 0; i < 3; ++i) {
    std::cout << "Enter lbs value: ";
    if (!(std::cin >> lbs)) {
      free_io();
      std::cout << "Enter a real number: ";
    }
    data[i + 3] = Stonewt(lbs, Stonewt::STN);
  }

// STATISTICS
  Stonewt min;
  Stonewt max;
  const int NUM = 11;
  int cnt11 = 0;
  for (int i = 0; i < SIZE; ++i) {
    if (i == 0) { min = data[i]; max = data[i]; } 
    min = data[i] < min ? data[i]: min;
    max = data[i] > max ? data[i]: max;
    data[i] >= NUM ? ++cnt11: cnt11;
  }

// SHOW STATS
  std::cout << "Minimal value: " << min << std::endl;
  std::cout << "Maximum value: " << max << std::endl;
  std::cout << "Number of elems greater or equal than " 
            << NUM << ": " << cnt11 << std::endl;

  clear_buffer();
  return 0;
}

void free_io(void) {
  if (std::cin.fail())
    std::cin.clear();
  clear_buffer();
}
void clear_buffer(void) {
  while (std::cin.get() != '\n')
    continue;
}
