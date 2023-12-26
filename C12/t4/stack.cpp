#include "stack.h"

Stack::Stack(int n) {
  if (n > MAX) {
    std::cout << "Maximum number of elements in stack has been exceeded.\n"
              << MAX << " elements will be allocated.\n";
    n = MAX;
  }
  pitems = new Item[n];
  size = n;
  top = 0;
}

Stack::Stack(const Stack& st) {
  pitems = new Item[st.size];
  for (int i = 0; i < st.top; ++i)
    pitems[i] = st.pitems[i];
  size = st.size;
  top = st.top;
}

Stack::~Stack() {
  delete[] pitems;
}

bool Stack::isempty() const {
  return top == 0;
}

bool Stack::isfull() const {
  return top == size;
}

bool Stack::push(const Item& item) {
  if (isfull()) {
    std::cout << "Error. Stack is already full.\n";
    return false;
  }
  pitems[top++] = item;
  return true;
}

bool Stack::pop(Item& item) {
  if (isempty()) {
    std::cout << "Error. Stack is already empty.\n";
    return false;
  }
  item = pitems[--top];
  return true;
}

Stack& Stack::operator=(const Stack& st) {
  if (this == &st)
    return *this;
  delete[] pitems;
  pitems = new Item[st.size];
  for (int i = 0; i < st.top; ++i)
    pitems[i] = st.pitems[i];
  size = st.size;
  top = st.top;
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Stack& st) {
  for (int i = 0; i < st.top; ++i)
    os << st.pitems[i] << " ";
  os << '\n';
  return os;
}
