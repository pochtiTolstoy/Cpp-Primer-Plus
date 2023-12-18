#ifndef LIST_H_
#define LIST_H_

typedef double Item;

struct Node {
  Item item;
  Node* next;
};

static const int MAX = 10;

class List {
private:
  Node* root;
  int items;
public:
  List();
  bool isfull(void) const;
  bool isempty(void) const;
  bool push(const Item&);
  bool pop(Item&);
  void visit(void (*pf)(Item&));
  ~List();
};

#endif
