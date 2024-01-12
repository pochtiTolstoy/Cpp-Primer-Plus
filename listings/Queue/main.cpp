#include <iostream>
#include "queue.h"

int main() {
  Customer c1;
  Queue q;
  q.enqueue(c1);
  std::cout << q.queuecount() << '\n';
  return 0;
}
