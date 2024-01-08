// friend_ntmp.cpp -- шаблонный класс с нешаблонными друзьями
#include <iostream>
template <typename T>
class HasFriend {
private:
  T item_;
  static int ct_;
public:
  HasFriend(const T& i) : item_(i) { ++ct_; }
  ~HasFriend() { --ct_; }
  friend void counts();
  friend void reports(const HasFriend<T>&);
};

template <typename T>
int HasFriend<T>::ct_ = 0;

void counts() {
  std::cout << "int count: " << HasFriend<int>::ct_ << "; ";
  std::cout << "double count: " << HasFriend<double>::ct_ << '\n';
}

void reports(const HasFriend<int>& hf) {
  std::cout << "HasFriend<int>: " << hf.item_ << '\n';
}

void reports(const HasFriend<double>& hf) {
  std::cout << "HasFriend<double>: " << hf.item_ << '\n';
}

int main() {
  std::cout << "No objects declared: ";
  counts();

  HasFriend<int> h1(10);
  std::cout << "After h1 declared: ";
  counts();

  HasFriend<int> h2(20);
  std::cout << "After h2 declared: ";
  counts();

  HasFriend<double> h3(10.5);
  std::cout << "After h3 declared: ";
  counts();

  reports(h1);
  reports(h2);
  reports(h3);

  return 0;
}
