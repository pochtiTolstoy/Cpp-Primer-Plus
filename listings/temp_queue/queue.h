#ifndef QUEUE_H_
#define QUEUE_H_

template <class Item>
class Queue {
private:
  enum { Q_SIZE = 10 };
  class Node {
  public:
    Item item;
    Node* next;
    Node(const Item& i): item(i), next(nullptr) {}
  };
  Node* front;
  Node* rear;
  int items;
  const int qsize;
  Queue(const Queue& q): qsize(0) {}
  Queue& operator=(const Queue& q) { return *this; }
public:
  Queue(int qs = Q_SIZE);
  ~Queue();
  bool isempty() const { return items == 0; }
  bool isfull() const { return items == qsize; }
  int queuecount() const { return items; }
  bool enqueue(const Item&);
  bool dequeue(Item&);
};

template <class Item>
Queue<Item>::Queue(int qs): front(nullptr), rear(nullptr), items(0), qsize(qs) {}

template <class Item>
Queue<Item>::~Queue() {
  Node* temp;
  while (front != nullptr) {
    temp = front;
    front = front->next;
    delete temp;
  }
}

template <class Item>
bool Queue<Item>::enqueue(const Item& item) {
  if (isfull()) return false;
  Node* add = new Node(item);
  ++items;
  if (front == nullptr) front = add;
  else rear->next = add;
  rear = add;
  return true;
}

template <class Item>
bool Queue<Item>::dequeue(Item& item) {
  if (isempty()) return false;
  item = front->item;
  --items;
  Node* temp = front;
  front = front->next;
  delete temp;
  if (items == 0) rear = nullptr;
  return true;
}

#endif /* QUEUE_H_ */
