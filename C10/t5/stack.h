#ifndef STACK_H_
#define STACK_H_

struct customer {
  char fullname[35];
  double payment;
};

typedef struct customer Item;

class Stack {
private:
  static const int MAX = 10;
  int top;
  Item items[MAX];
public:
  Stack();
  bool push(const Item&);
  bool pop(Item&);
  bool isfull(void) const;
  bool isempty(void) const;
};

#endif
