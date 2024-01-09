#include <cstring>
#include <iostream>
#include "worker.h"
#include "queue.h"

const int SIZE = 5;

int main() {
  QueueTp<Worker*> lolas(SIZE);
  int ct;
  for (ct = 0; ct < SIZE; ++ct) {
    char choice;
    std::cout << "Enter the employee category:\n"
      << "w: waiter s: singer "
      << "t: singing waiter q: quit\n";
    std::cin >> choice;
    while (std::strchr("wstq", choice) == NULL) {
      std::cout << "Please enter a w, s, t, or q: ";
      std::cin >> choice;
    }
    if (choice == 'q') break;
    switch (choice) {
      case 'w': lolas.push(new Waiter);
        break;
      case 's': lolas.push(new Singer);
        break;
      case 't': lolas.push(new SingingWaiter);
        break;
    }
    std::cin.get();
    lolas.tail()->Set();
  }
  std::cout << "\nHere is your staff:\n";
  lolas.print();

  std::cout << "Bye!\n";
  // no leaks because of Worker* specialization
  return 0;
}
