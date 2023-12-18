#include <iostream>
#include "stack.h"

Stack::Stack() { top = 0; }

bool Stack::push(const Item& item) {
  if (isfull()) { return false; }
  items[top++] = item;
  return true;
}

bool Stack::pop(Item& item) {
  if (isempty()) { return false; }
  item = items[--top];
  return true;
}

bool Stack::isfull(void) const { return top == MAX; }

bool Stack::isempty(void) const { return top == 0; }
