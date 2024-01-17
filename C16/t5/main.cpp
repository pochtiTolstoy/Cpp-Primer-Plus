#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

template <typename T>
int reduce(T ar[], int n);

template <typename T>
void print(T ar[], int n);

int main() {
  int SIZE = 30;
  const int Range = 10;
  int ar[SIZE];
  std::srand(std::time(0));
  for (int i = 0; i < SIZE; ++i)
    ar[i] = rand() % Range + 1;
  print(ar, SIZE);
  int items = reduce(ar, SIZE);
  print(ar, items);

  SIZE = 7; 
  std::string stringArr[SIZE] = {
    "hello", "bye", "boat",
    "bye", "hello", "hell", "hello"
  };
  print(stringArr, SIZE);
  int item = reduce(stringArr, SIZE);
  print(stringArr, item);
  return 0;
}

template <typename T>
int reduce(T ar[], int n) {
  std::sort(ar, ar + n);
  auto end = std::unique(ar, ar + n);
  return end - ar;
}

template <typename T>
void print(T ar[], int n) {
  for (int i = 0; i < n; ++i)
    std::cout << ar[i] << ' ';
  std::cout << '\n';
}
