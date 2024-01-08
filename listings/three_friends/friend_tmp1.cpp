// Шаблонные друзья для шаблонного класса, связанные
#include <iostream>

template <typename T> void counts();
template <typename T> void report(T&);

template <typename T>
class HasFriend {
private:
  T item_;
  static int ct_;
public:
  HasFriend(const T& i): item_(i) { ++ct_; }
  ~HasFriend() { --ct_; }
  friend void counts<T>();
  friend void report<>(HasFriend<T>&);
};

template <typename T>
int HasFriend<T>::ct_ = 0;

template <typename T>
void counts() {
  std::cout << "template size: " << sizeof(HasFriend<T>) << "; ";
  std::cout << "template counts(): " << HasFriend<T>::ct_ << '\n';
}

template <typename T>
void report(T& hf) {
  std::cout << hf.item_ << '\n';
}

int main() {
  counts<int>(); // Провоцирует генерацию класса по шаблону (?)
  HasFriend<int> h1(10);
  HasFriend<int> h2(20);
  HasFriend<double> h3(10.5);
  report(h1);
  report(h2);
  report(h3);
  std::cout << "counts<int>() output:\n";
  counts<int>();
  std::cout << "counts<double>() output:\n";
  counts<double>();
  return 0;
}
