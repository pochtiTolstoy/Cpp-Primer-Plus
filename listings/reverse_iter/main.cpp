#include <iostream>
#include <iterator>
#include <vector>

int main() {
  int casts[10] = { 6, 7, 2, 9, 4, 11, 8, 7, 10, 5 };
  std::vector<int> dice(10);
  std::copy(casts, casts + 10, dice.begin());
  std::cout << "Dice: \n";
  std::ostream_iterator<int, char> out_iter(std::cout, " ");
  std::copy(dice.begin(), dice.end(), out_iter);
  std::cout << '\n';
  std::cout << "Implicit use of reverse iterator:\n";
  std::copy(dice.rbegin(), dice.rend(), out_iter);
  std::cout << '\n';

  std::vector<int>::reverse_iterator ri;
  std::cout << "Explicit use of reverse iterator:\n";
  for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
    std::cout << *ri << ' ';
  std::cout << '\n';
  return 0;
}
