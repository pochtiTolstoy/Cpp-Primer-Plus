#include <iostream>
#include <cctype>
#include "stack.h"

void clear_buffer(void);

int main() {
  double balance = 0.0;
  char ch;
  Stack st;
  customer c;

  std::cout << "Please enter A to add a customer,\n"
            << "P to remove a customer, or Q to quit.\n";
  while ((std::cin >> ch) && toupper(ch) != 'Q') {
    clear_buffer();
    if (!isalpha(ch)) {
      std::cout << "Error, enter charachter: ";
      continue;
    }
    switch (ch) {
      case 'A' :
      case 'a' :
        std::cout << "Enter a customer's fullname: ";
        std::cin.getline(c.fullname, 35);
        std::cout << "Enter the customers's payment: ";
        (std::cin >> c.payment).get();
        if (st.isfull()) {
          std::cout << "Stack already full\n";
        } else {
          st.push(c);
        }
        break;
      case 'P' :
      case 'p' :
        if (st.isempty()) {
          std::cout << "Stack already empty\n";
        } else {
          st.pop(c);
          std::cout << "Customer " << c.fullname << " popped\n";
          balance += c.payment;
        }
        break;
    }
    std::cout << "The total payment is " << balance << std::endl;
    std::cout << "Please enter A to add a customer,\n"
              << "P to remove a customer, or Q to quit.\n";
  }

  std::cout << "Final balance: " << balance << std::endl;
  return 0;
}

void clear_buffer(void) {
  while (std::cin.get() != '\n')
    continue;
}
