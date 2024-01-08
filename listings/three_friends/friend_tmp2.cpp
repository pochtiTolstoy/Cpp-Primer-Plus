// не связанная шаблонная функция, дружественная шаблонному классу
#include <iostream>
template <typename T>
class ManyFriend {
private:
  T item_;
public:
  ManyFriend(const T& i): item_(i) {}
  template <typename C, typename D> friend void show2(C&, D&);
};

template <typename C, typename D> void show2(C& c, D& d) {
  std::cout << c.item_ << ", " << d.item_ << '\n';
}

int main() {
  ManyFriend<int> h1(10);
  ManyFriend<int> h2(20);
  ManyFriend<double> h3(10.5);
  std::cout << "h1, h2: ";
  show2(h1, h2);
  std::cout << "h3, h2: ";
  show2(h3, h2);
  return 0;
}
