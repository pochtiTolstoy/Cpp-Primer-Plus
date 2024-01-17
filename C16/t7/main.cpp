#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

std::vector<int> Lotto(int, int);
void show(const std::vector<int> v);

int main() {
  std::srand(std::time(0));
  std::vector<int> v = Lotto(10, 5);
  std::copy(v.begin(), v.end(), std::ostream_iterator<int, char>(std::cout, " "));
  return 0;
}

std::vector<int> Lotto(int range, int amount) {
  if (range < 1) {
    std::cout << "Range is too small.\n";
    return std::vector<int>();
  }
  if (amount > range) {
    std::cout << "Amount is too big.\n";
    return std::vector<int>();
  }
  std::vector<int> temp;
  for (int i = 1; i < range; ++i)
    temp.push_back(i);
  show(temp);
  std::random_shuffle(temp.begin(), temp.end());
  temp.erase(temp.begin() + amount, temp.end());
  return temp;
}

void show(const std::vector<int> v) {
  for (auto x: v) std::cout << x << ' ';
  std::cout << '\n';
}
