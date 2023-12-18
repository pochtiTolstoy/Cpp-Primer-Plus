#include <iostream>
#include "bank.h"

int main() {
  char name[] = "Apple Green";
  char number[] = "10090030400534205";
  Bank b1; //default constuctor
  Bank b2(name, number, 100);
  std::cout << "Showing data:\n";
  b1.show_data();
  b2.show_data();

  std::cout << "\nLets add money! :)\n";
  b1.add_money(100.5);
  b2.add_money(99.9);
  b1.show_data();
  b2.show_data();

  std::cout << "\nLets decrease money! ;(\n";
  b1.withdraw_money(100000);
  b2.withdraw_money(5);
  b1.show_data();
  b2.show_data();

  std::cout << "Bye.\n";
  return 0;
}
