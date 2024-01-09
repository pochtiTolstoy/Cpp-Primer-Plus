#include <iostream>
#include <vector>

template <typename T, template<typename> class Container>
class Stack {
private:
  Container<T> container;
public:
  void push(T elem) {
    container.push_back(elem); 
  }
  T& operator[](int i) {
    return container[i];
  }
};


int main() {
  Stack<int, std::vector> st;
  st.push(10);
  st.push(16);
  std::cout << st[0] << '\n';
  std::cout << st[1] << '\n';
  return 0;
}
