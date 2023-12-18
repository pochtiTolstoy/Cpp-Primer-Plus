#include <iostream>
#include "sales.h"

int main() {
  const int size = 8;
  double ar[size] = { 100, 200, 177.3, 2.3, 5, 6, 100, 1000 };
  SALES::Sales data1;
  SALES::Sales data2(ar, size);
  data1.showSales();
  data2.showSales();
  return 0;
}
