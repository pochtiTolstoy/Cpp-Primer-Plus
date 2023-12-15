#include <iostream>
#include <cstring>

template<typename T>
T maxn(T [], int);

template<> const char* maxn<const char*>(const char* arr[], int n);

int main() {
  int arr1[6] = { 1, 2, 3, 4, 5, 6 };
  double arr2[4] = { 2.22, 3.33, 4.44, 0.22 };
  const char* messages[5] = {
    "Good morning!",
    "How are you today?",
    "I am feeling great.",
    "What are you doing???",
    "Hello!"
  };
  std::cout << "Max in int array: " << maxn(arr1, 6) << std::endl;
  std::cout << "Max in double array: " << maxn(arr2, 4) << std::endl;
  std::cout << "Max string in array: " << maxn(messages, 5) << std::endl;

  return 0;
}

template<typename T>
T maxn(T arr[], int n) {
  T max_val = arr[0];
  for (int i = 1; i < n; ++i)
    max_val = arr[i] > max_val ? arr[i] : max_val;
  return max_val;
}

template<> const char* maxn<const char*>(const char* arr[], int n) {
  const char* ptr = arr[0];
  for (int i = 0; i < n; ++i)
    ptr = strlen(arr[i]) > strlen(ptr) ? arr[i] : ptr; 
  return ptr;
}
