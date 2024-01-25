#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

const long Size1 = 39L;
const long Size2 = 100 * Size1;
const long Size3 = 100 * Size2;

bool f3(int x) { return x % 3 == 0; }
bool f13(int x) { return x % 13 == 0; }

int main() {
  std::vector<int> numbers(Size1);
  std::srand(std::time(0));
  std::generate(numbers.begin(), numbers.end(), std::rand);
  std::cout << "Sample size = " << Size1 << '\n';
  int count3 = std::count_if(numbers.begin(), numbers.end(), f3);
  std::cout << "Count of numbers divisible by 3: " << count3 << '\n';
  int count13 = std::count_if(numbers.begin(), numbers.end(), f13);
  std::cout << "Count of numbers divisible by 13: " << count13 << '\n';

  numbers.resize(Size2);
  std::generate(numbers.begin(), numbers.end(), std::rand);
  std::cout << "Sample size = " << Size2 << '\n';
  class f_mod {
  private:
    int dv;
  public:
    f_mod(int d = 1): dv(d) {}
    bool operator()(int x) { return x % dv == 0; }
  };
  count3 = std::count_if(numbers.begin(), numbers.end(), f_mod(3));
  // creating object with dv = 3
  std::cout << "Count of numbers divisible by 3: " << count3 << '\n';
  count13 = std::count_if(numbers.begin(), numbers.end(), f_mod(13));
  std::cout << "Count of numbers divisible by 13: " << count13 << '\n';

  numbers.resize(Size3);
  std::generate(numbers.begin(), numbers.end(), std::rand);
  std::cout << "Sample size = " << Size3 << '\n';
  count3 = std::count_if(numbers.begin(), numbers.end(),
                        [](int x) { return x % 3 == 0; });
  std::cout << "Count of numbers divisible by 3: " << count3 << '\n';
  count13 = std::count_if(numbers.begin(), numbers.end(),
                        [](int x) { return x % 13 == 0; });
  std::cout << "Count of numbers divisible by 13: " << count13 << '\n';
  return 0;
}
