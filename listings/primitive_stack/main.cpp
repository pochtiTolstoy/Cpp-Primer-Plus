#include <iostream>
#include <cctype>
#include "stack.h"

void clear_buffer(void);

int main() {
  Stack st;
  char ch;
  unsigned long po;
  std::cout << "Please enter A to add a purchase order,\n"
            << "P to process a PO, or Q to quit.\n";
  while ((std::cin >> ch) && toupper(ch) != 'Q') {
    clear_buffer();
    if (!isalpha(ch)) {
      std::cout << "Error input. Please enter the charachter: ";
      continue;
    }
    switch (ch) {
      case 'A' :
      case 'a' :
        std::cout << "Enter a PO number to add: ";
        std::cin >> po;
        if (st.isfull())
          std::cout << "Stack already full\n";
        else
          st.push(po);
        break;
      case 'P' :
      case 'p' :
        if (st.isempty())
          std::cout << "Stack already empty\n";
        else {
          st.pop(po);
          std::cout << "PO #" << po << " popped\n";
        }
        break;
    }
    std::cout << "Please enter A to add a purchase order,\n"
              << "P to process a PO, or Q to quit.\n";
  }
  std::cout << "Bye\n";

  return 0;
}

void clear_buffer(void) {
  while (std::cin.get() != '\n')
    continue;
}
