#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>


int main() {
  int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
  std::list<int> a(vals, vals + 10);
  std::list<int> b(vals, vals + 10);
  auto outint = [](int n) { std::cout << n << " "; };

  std::cout << "Showing lists:\n";
  for_each(a.begin(), a.end(), outint);
  std::cout << '\n';
  for_each(b.begin(), b.end(), outint);
  std::cout << '\n';

  a.remove_if([](int t) { return t < 100; });
  b.remove_if([](int t) { return t < 200; });

  std::cout << "After removing:\n";
  for_each(a.begin(), a.end(), outint);
  std::cout << '\n';
  for_each(b.begin(), b.end(), outint);
  std::cout << '\n';

  return 0;
}
