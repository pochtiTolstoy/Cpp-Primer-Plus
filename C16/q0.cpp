#include <iostream>
#include <vector>
#include <valarray>
#include <functional>

template <typename T>
void show_arr(const T& v) {
  for (auto x: v) std::cout << x << ' ';
  std::cout << '\n';
}

void calc_expression(
  std::vector<double>& v1,
  std::vector<double>& v2,
  std::vector<double>& v3
);

int main() {
  std::valarray<double> vad1 = { 1, 2, 3, 4, 5 };
  std::valarray<double> vad2 = { 0.1, 0.2, 0.3, 0.4, 0.5 };
  std::valarray<double> vad3(5); 
  vad3 = 10.0 * ((vad1 + vad2) / 2.0 + vad1 * cos(vad2));
  std::cout << "Source valarrays:\n";
  show_arr(vad1);
  show_arr(vad2);
  std::cout << "Calculate expression with valarray:\n";
  show_arr(vad3);

  // calculate same expression with stl vector:
  // copy valarrays to vectors:
  std::vector<double> v1(5), v2(5), v3(5); 
  std::copy(std::begin(vad1), std::end(vad1), v1.begin());
  std::copy(std::begin(vad2), std::end(vad2), v2.begin());
  std::cout << "\nValues of vectors created from valarrays:\n";
  show_arr(v1);
  show_arr(v2);
  calc_expression(v1, v2, v3);
  std::cout << "\nResult using valarray:\n";
  show_arr(vad3);
  std::cout << "Result using STL vectors:\n";
  show_arr(v3);
  return 0;
}

void calc_expression(
  std::vector<double>& v1,
  std::vector<double>& v2,
  std::vector<double>& v3
) {
  // Calculate v1 + v2:
  std::transform(
    v1.begin(), v1.end(), v2.begin(), 
    v3.begin(), std::plus<double>()
  );
  //show_arr(v3);

  // Calculate (v1 + v2) / 2.0:
  std::transform(
    v3.begin(), v3.end(), 
    v3.begin(), bind2nd(std::divides<double>(), 2.0)
  );
  //show_arr(v3);

  // Calculate cos(v2):
  std::vector<double> temp(5);
  std::transform(
    v2.begin(), v2.end(), 
    temp.begin(), cos
  );
  //show_arr(temp);

  // Calculate v1 * cos(v2):
  std::transform(
    temp.begin(), temp.end(), v1.begin(),
    temp.begin(), std::multiplies<double>()
  );
  //show_arr(temp);

  // Calculate ((v1 + v2) / 2.0) + (v1 * cos(v2)) (v3 + temp):
  std::transform(
    v3.begin(), v3.end(), temp.begin(),
    v3.begin(), std::plus<double>()
  );
  //show_arr(v3);

  // Calculate v3 * 10.0:
  std::transform(
    v3.begin(), v3.end(),
    v3.begin(), bind1st(std::multiplies<double>(), 10.0)
  );
  //show_arr(v3);
}
