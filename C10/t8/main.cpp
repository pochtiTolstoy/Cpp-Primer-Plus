// 1. test empty
// 2. test full
// 3. test push
// 4. test destructor
// 5. test pop
// 6. traverse

#include <iostream>
#include "list.h"

void inc(Item& it);
void show_item(Item& it);

int main() {
  {
    Item tmp;
    List l1;
    std::cout << "Empty? " << l1.isempty() << std::endl;
    std::cout << "Full? " << l1.isfull() << std::endl;
    l1.pop(tmp);
    l1.push(3.44);
    l1.pop(tmp);
    std::cout << "popped item: " << tmp << std::endl;

    l1.push(10);
    l1.push(11);
    l1.push(12);
    l1.push(13);

    l1.visit(show_item);
    l1.visit(inc);
    l1.visit(show_item);

    l1.push(14);
    l1.push(15);
    l1.push(16);
    l1.push(17);
    l1.push(18);
    l1.push(19);
    l1.push(10);
    l1.push(10);
    l1.push(10);

    l1.visit(show_item);
    l1.visit(inc);
    l1.visit(show_item);

    std::cout << "Empty? " << l1.isempty() << std::endl;
    std::cout << "Full? " << l1.isfull() << std::endl;

    l1.pop(tmp);
    std::cout << "popped item: " << tmp << std::endl;
    std::cout << "Empty? " << l1.isempty() << std::endl;
    std::cout << "Full? " << l1.isfull() << std::endl;
  } //to test destructor
  return 0;
}

void inc(Item& it) {
  ++it;
}

void show_item(Item& it) {
  std::cout << "Item: " << it << std::endl;
}
