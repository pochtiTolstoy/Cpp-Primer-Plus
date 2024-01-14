#include <iostream>
#include <iterator>
#include <functional>
#include <vector>

double mean(double a, double b) {
  return (a + b) / 2;
}

double pow(double a) { return a * a; }

int main() {
  std::vector<double> ar1 = {1, 2, 3, 4, 5};
  std::vector<double> ar2 = { 100, 200, 300};
  std::ostream_iterator<double, char> out(std::cout, " ");

  std::cout << "Source vectors:\n";
  std::copy(ar1.begin(), ar1.end(), out);
  std::cout << '\n';
  std::copy(ar2.begin(), ar2.end(), out);
  std::cout << '\n';

  std::cout << "Transformed vectors:\n";
  std::transform(ar1.begin(), ar1.end(), out, pow); // First version of transform
  std::cout << '\n';
  std::transform(ar2.begin(), ar2.end(), out, pow); // First version of transform
  std::cout << '\n';
  // Если выходим за границы, то считаем, что в векторе остались нули

  std::transform(ar1.begin(), ar1.end(), ar2.begin(), out, mean); // Second version
  std::cout << '\n';

  return 0;
}
