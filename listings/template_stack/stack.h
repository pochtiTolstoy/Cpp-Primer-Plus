#ifndef STACK_H_
#define STACK_H_

// Реализация также в .h файле, потому что шаблонные методы не должны выноситься
// в отдельный файл

template <class T>
class Stack {
private:
  enum { SIZE = 10 };
  // order matters!
  int stacksize_; // Размер стека, меняется в конструкторе, по умолчанию равно 10
  T* items_; // динамическое выделение памяти, в памяти лежат элементы T
  int top_; // Указатель на вершину стека
public:
  explicit Stack(int ss = SIZE); // + по умолчанию, запрет функции преобразования
  Stack(const Stack& st); // Конструктор копирования
  ~Stack() { delete[] items_; } // Удаляем динамический массив по указателю items_
  bool isempty() { return top_ == 0; } // inline
  bool isfull() { return top_ == stacksize_; } // inline
  bool push(const T& item); // добавление item в стек
  bool pop(T& item);        // выталкивание верхнего элемента в item
  Stack& operator=(const Stack& st); // Опертаор присваивания, правило трёх
};

// реализация
template <class T>
Stack<T>::Stack(int ss)
  : stacksize_(ss), items_(new T[stacksize_]), top_(0) {}

template <class T>
Stack<T>::Stack(const Stack& st)
  : stacksize_(st.stacksize_), items_(new T[stacksize_]), top_(st.top_) {
  for (int i = 0; i < top_; ++i)
    items_[i] = st.items_[i];
}

template <class T>
bool Stack<T>::push(const T& item) {
  if (isfull()) return false;
  items_[top_++] = item; // copy
  return true;
}

template <class T>
bool Stack<T>::pop(T& item) {
  if (isempty()) return false;
  item = items_[--top_]; // копирование через ссылку
  return true;
}

template <class T> // Возвращать нужно также специализированный класс
Stack<T>& Stack<T>::operator=(const Stack<T>& st) {
  if (this == &st)
    return *this;
  delete[] items_;
  stacksize_ = st.stacksize_;
  items_ = new T[stacksize_];
  top_ = st.top_;
  for (int i = 0; i < top_; ++i)
    items_[i] = st.items_[i];
  return *this;
}

#endif
