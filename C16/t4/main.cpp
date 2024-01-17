#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>

int reduce(long ar[], int n);
void print(long ar[], int n);

int main() {
  const int SIZE = 30;
  const int Range = 50;
  long ar[SIZE];
  std::srand(std::time(0));
  for (int i = 0; i < SIZE; ++i)
    ar[i] = rand() % Range + 1;
  print(ar, SIZE);
  int items = reduce(ar, SIZE);
  print(ar, items);
  return 0;
}

int reduce(long ar[], int n) {
  std::sort(ar, ar + n);
  long* end = std::unique(ar, ar + n);
  return end - ar;
}

void print(long ar[], int n) {
  for (int i = 0; i < n; ++i)
    std::cout << ar[i] << ' ';
  std::cout << '\n';
}
