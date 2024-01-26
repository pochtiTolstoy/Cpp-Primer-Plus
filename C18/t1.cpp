#include <iostream>

template <typename T>
T average_list(std::initializer_list<T>);

int main() {
  auto q = average_list({15.4, 10.7, 9.0});
  std::cout << q << '\n';

  std::cout << average_list({20, 30, 18, 17, 45, 38}) << '\n';

  auto ad = average_list<double>({'A', 70, 65.33});
  std::cout << ad << '\n';

  return 0;
}

template <typename T>
T average_list(std::initializer_list<T> li) {
  T sum = 0;
  int count = 0;
  for (const auto& elem: li) {
    sum += elem;
    ++count;
  }
  return sum / count;
}
