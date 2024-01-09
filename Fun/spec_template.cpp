#include <iostream>

template <typename T, typename U>
void f(T, U) {
  std::cout << 1 << '\n';
}

template <>
void f(int, int) {
  std::cout << 2 << '\n';
}

template <typename T>
void f(T, T) {
  std::cout << 3 << '\n';
}

int main() {
  f(0, 0.0); // 1
  f(0.0, 0.0); // 3
  f(0, 0); // 3
  // Выигрывает первый шаблон, т.к. указали два типа
  // И попали в специализацию
  f<int, int>(0, 0); // 2
  return 0;
}
