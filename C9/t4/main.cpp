#include <iostream>
#include "sales.h"

int main() {
  SALES::Sales data1;  
  SALES::Sales data2;  
  SALES::setSales(data1);
  const int size = 8;
  double ar[size] = { 100, 200, 177.3, 2.3, 5, 6, 100, 1000 };
  SALES::setSales(data2, ar, size);
  showSales(data1);
  showSales(data2);
  return 0;
}
