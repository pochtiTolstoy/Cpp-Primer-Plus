#include <iostream>
#include "list.h"

List::List() {
  root = nullptr;
  items = 0;
}

bool List::isfull(void) const {
  return items == MAX;
}

bool List::isempty(void) const {
  return items == 0;
}

bool List::push(const Item& it) {
  if (isfull()) {
    std::cout << "Error. Stack already full.\n";    
    return false;
  }
  ++items;
  Node* new_node = new Node;
  new_node->item = it;
  new_node->next = nullptr;
  if (root == nullptr) {
    root = new_node;
    return true;
  }
  Node* find = root; // root is not empty
  while (find->next != nullptr)
    find = find->next;
  find->next = new_node;
  return true;
}

bool List::pop(Item& it) {
  // if root is null then there isnothing to delete
  if (root == nullptr) {
    std::cout << "Stack is empty, nothing to pop.\n";
    return false;
  }
  // if we have only one elem
  if (root->next == nullptr) {
    --items;
    it = root->item;
    delete root;
    root = nullptr;
    return true;
  }
  // we have two or more elements
  --items;
  Node* p2 = root; //ptr to first elem
  Node* p1 = root->next; //ptr to second elem 
  //check third elem
  while (p1->next != nullptr) {
    p2 = p1;
    p1 = p1->next;
  }
  it = p1->item;
  p2->next = nullptr;
  delete p1;
  return true;
}

void List::visit(void (*pf)(Item&)) {
  Node* walk = root;
  while (walk != nullptr) {
    (*pf)(walk->item); 
    walk = walk->next;
  }
}

List::~List() {
  Node* tmp;
  while (root != nullptr) {
    tmp = root; 
    root = root->next;
    delete tmp;
  }
}
