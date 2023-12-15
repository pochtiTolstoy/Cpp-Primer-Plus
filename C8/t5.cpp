#include <iostream>

const int size = 5;

template<typename T>
T max5(const T arr[]);

int main() {
  int arr1[size] = { 10, 2, 4, 5, -1 };
  double arr2[size] = { 2.2, 3.6, 6.2, 0 };
  std::cout << "Max in int arr: " << max5(arr1) << std::endl;
  std::cout << "Max in double arr: " << max5(arr2) << std::endl;
  return 0;
}

template<typename T>
T max5(const T arr[]) {
  T max = arr[0];
  for (int i = 1; i < size; ++i)
    max = arr[i] > max ? arr[i] : max;
  return max;
}
