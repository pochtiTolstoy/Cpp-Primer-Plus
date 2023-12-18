#include <iostream>
#include "sales.h"

namespace SALES {
  Sales::Sales() {
    for (int i = 0; i < QUARTERS; ++i)
      sales[i] = 0.0;
    min = max = average = 0.0;
  }

  Sales::Sales(const double ar[], int n) {
    if (n <= 0) {
      for (int i = 0; i < QUARTERS; ++i)
        sales[i] = -1;
      return;
    }
    max = min = ar[0];
    average = 0;
    int size = n > QUARTERS ? QUARTERS : n;
    for (int i = 0; i < size; ++i) {
      sales[i] = ar[i]; 
      max = ar[i] > max ? ar[i] : max;
      min = ar[i] < min ? ar[i] : min;
      average += ar[i];
    }
    average /= size;
    while (n < QUARTERS) // set no info about other quaters
      sales[n++] = -1;
  }

  void Sales::setSales(void) {
    double temp[QUARTERS];
    for (int i = 0; i < QUARTERS; ++i) {
//----Read-data-------------------------------------------------
      std::cout << "Enter sales for quarter #" << i + 1
                << ": ";
      while (!(std::cin >> temp[i])) {
        std::cin.clear();
        while (std::cin.get() != '\n')
          continue;
        std::cout << "Please, enter a real number: ";
      }
      while (std::cin.get() != '\n')
        continue;
      }
//--------------------------------------------------------------
    *this = Sales(temp, QUARTERS); 
  }

  void Sales::showSales(void) const {
    std::cout << "Show sales:\n";
    int i = 0;
    while (i < QUARTERS && sales[i] != -1) {
      std::cout << "Quarter #" << i + 1 << ": " << sales[i] << std::endl; 
      ++i;
    }
    if (i == 0) {
      std::cout << "There is no data about quarters.\n";
      return;
    }
    std::cout << "Average value: " << average << std::endl;
    std::cout << "Min value: " << min << std::endl;
    std::cout << "Max value: " << max << std::endl;
  }
}
