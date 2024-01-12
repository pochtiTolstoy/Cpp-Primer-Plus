#include <iostream>
#include <string>
#include "queue.h"

int main() {
  Queue<std::string> cs(5);
  std::string temp;
  while (!cs.isfull()) {
    std::cout << "Please enter your name. You will be "
      " served in the order of arrival.\n"
      "name: ";
    std::getline(std::cin, temp);
    cs.enqueue(temp);
  }
  std::cout << "The queu is full. Processing begins!\n";
  while (!cs.isempty()) {
    cs.dequeue(temp);
    std::cout << "Now processing " << temp << "...\n";
  }
  return 0;
}
