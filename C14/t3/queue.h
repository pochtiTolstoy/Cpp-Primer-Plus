#ifndef QUEUE_H_
#define QUEUE_H_
#include "worker.h"

template <typename T>
class Node {
private:
  T item_;
  Node<T>* next_;
public:
  Node() = delete;
  Node(const T& item, Node<T>* next): item_(item), next_(next) {};
  void set_next(Node<T>* next) { next_ = next; }
  Node<T>* get_next() { return next_; }
  T& get_item() { return item_; }
  void print() const;
};

template <typename T>
class QueueTp {
private:
  static const size_t SIZE = 5;
  const size_t max_size_;
  unsigned int count_item_;
  Node<T>* head_; 
  Node<T>* tail_;
public:
  QueueTp(size_t max_size = SIZE);
  bool push(const T&);
  bool pop(T&);
  bool isfull() const { return count_item_ == max_size_; }
  bool isempty() const { return count_item_ == 0; }
  void print() const;
  T& tail() { return tail_->get_item(); }
  ~QueueTp();
};

template <typename T>
QueueTp<T>::QueueTp(size_t max_size)
  : max_size_(max_size), count_item_(0), head_(nullptr), tail_(nullptr) {}

template <typename T>
bool QueueTp<T>::push(const T& item) {
  if (isfull()) return false;
  Node<T>* p_node = new Node<T>(item, nullptr);
  if (isempty()) head_ = p_node; 
  else tail_->set_next(p_node);
  tail_ = p_node;
  ++count_item_;
  return true;  
}

template <typename T>
bool QueueTp<T>::pop(T& item) {
  if (isempty()) return false;
  if (head_ == tail_) tail_ = nullptr;
  item = head_->get_item();
  Node<T>* p_temp = head_;
  head_ = head_->get_next();
  delete p_temp;
  --count_item_;
  return true;
}

template <typename T>
void QueueTp<T>::print() const {
  Node<T>* p_node = head_;
  while (p_node != nullptr) {
    std::cout << p_node->get_item() << '\n'; 
    p_node = p_node->get_next();
  }
}

template <typename T>
QueueTp<T>::~QueueTp() {
  Node<T>* p_temp;
  while (head_ != nullptr) {
    p_temp = head_;
    head_ = head_->get_next();
    delete p_temp; 
  }
}

template <>
void QueueTp<Worker*>::print() const {
  Node<Worker*>* p_node = head_;
  while (p_node != nullptr) {
    p_node->get_item()->Show();
    std::cout << '\n';
    p_node = p_node->get_next();
  }
}

template <>
QueueTp<Worker*>::~QueueTp() {
  Node<Worker*>* p_temp;
  while (head_ != nullptr) {
    p_temp = head_;
    head_ = head_->get_next();
    delete p_temp->get_item();
    delete p_temp; 
  }
}

#endif /* QUEUE_H_ */
