#include <iostream>

template <typename T, typename... Args>
long double sum_values(T value, Args... args);

template <typename T>
long double sum_values(T value);

int main() {
  std::cout << sum_values(1, 2, 3, 4, 5) << '\n';
  std::cout << sum_values(12,18,50.5,10.4,9.1) << '\n';
  return 0;
}

template <typename T, typename... Args>
long double sum_values(T value, Args... args) {
  return value + sum_values(args...);
}

template <typename T>
long double sum_values(T value) {
  return value;
}
