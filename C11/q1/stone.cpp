#include <iostream>
#include "stonewt.h"

void display(const Stonewt& st, int n);

int main() {
  Stonewt obj(10, 8.0);
  obj.show_stn();
  obj = obj * 2;
  obj.show_stn();

  return 0;
}

void display(const Stonewt& st, int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << "Wow! ";
    st.show_stn();
  }
}
