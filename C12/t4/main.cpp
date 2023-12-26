#include <iostream>
#include "stack.h"

int main() {
  std::cout << "Test constructor:\n";
  Stack st(3);
  std::cout << "Empty?: " << st.isempty() << std::endl;
  std::cout << "\nTest add function:\n";
  st.push(100);
  st.push(200);
  st.push(300);
  std::cout << st;

  std::cout << "Is full?: " << st.isfull() << std::endl;

  std::cout << "\nTest copy constructor:\n";
  Stack st1 = st;
  std::cout << st1;

  std::cout << "\nTest assignment operator:\n";
  Stack st2;
  st2 = st;
  std::cout << st2;

  std::cout << "\nTest pop function:\n";
  unsigned long temp = 0;
  st.pop(temp);
  std::cout << "temp = " << temp << std::endl;
  std::cout << st;

  return 0;
}
