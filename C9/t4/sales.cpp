#include <iostream>
#include "sales.h"

namespace SALES {
  void setSales(Sales& s, const double ar[], int n) {
    if (n <= 0) {
      for (int i = 0; i < QUARTERS; ++i)
        s.sales[i] = -1;
      return;
    }
    s.max = s.min = ar[0];
    s.average = 0;
    int size = n > QUARTERS ? QUARTERS : n;
    for (int i = 0; i < size; ++i) {
      s.sales[i] = ar[i]; 
      s.max = ar[i] > s.max ? ar[i] : s.max;
      s.min = ar[i] < s.min ? ar[i] : s.min;
      s.average += ar[i];
    }
    s.average /= size;
    while (n < QUARTERS) // set no info about other quaters
      s.sales[n++] = -1;
  }

  void setSales(Sales& s) {
    for (int i = 0; i < QUARTERS; ++i) {
//----Read-data-------------------------------------------------
      std::cout << "Enter sales for quarter #" << i + 1
                << ": ";
      while (!(std::cin >> s.sales[i])) {
        std::cin.clear();
        while (std::cin.get() != '\n')
          continue;
        std::cout << "Please, enter a real number: ";
      }
      while (std::cin.get() != '\n')
        continue;
//--------------------------------------------------------------
      if (i == 0) { 
        s.max = s.min = s.sales[i];
        s.average = 0; 
      }
      s.max = s.sales[i] > s.max ? s.sales[i] : s.max; 
      s.min = s.sales[i] < s.min ? s.sales[i] : s.min; 
      s.average += s.sales[i];
    }
    s.average /= QUARTERS;
  }

  void showSales(const Sales& s) {
    std::cout << "Show sales:\n";
    int i = 0;
    while (i < QUARTERS && s.sales[i] != -1) {
      std::cout << "Quarter #" << i + 1 << ": " << s.sales[i] << std::endl; 
      ++i;
    }
    if (i == 0) {
      std::cout << "There is no data about quarters.\n";
      return;
    }
    std::cout << "Average value: " << s.average << std::endl;
    std::cout << "Min value: " << s.min << std::endl;
    std::cout << "Max value: " << s.max << std::endl;
  }
}
