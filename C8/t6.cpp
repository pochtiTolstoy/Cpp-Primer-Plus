#include <iostream>

template<typename T>
T maxn(T [], int);

int main() {
  int arr1[6] = { 1, 2, 3, 4, 5, 6 };
  double arr2[4] = { 2.22, 3.33, 4.44, 0.22 };
  std::cout << "Max in int array: " << maxn(arr1, 6) << std::endl;
  std::cout << "Max in double array: " << maxn(arr2, 4) << std::endl;
  return 0;
}

template<typename T>
T maxn(T arr[], int n) {
  T max_val = arr[0];
  for (int i = 1; i < n; ++i)
    max_val = arr[i] > max_val ? arr[i] : max_val;
  return max_val;
}
