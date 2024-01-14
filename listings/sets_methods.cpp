#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

int main() {
  const int N = 6;
  std::string s1[N] = { "buffon", "thinkers", "for", "heavy", "can", "for" };
  std::string s2[N] = { "metal", "any", "food", "elegant", "deliver", "for" };
  std::set<std::string> A(s1, s1 + N);
  std::set<std::string> B(s2, s2 + N);
  std::ostream_iterator<std::string, char> out(std::cout, " ");
  std::cout << "Set A: ";
  std::copy(A.begin(), A.end(), out);
  std::cout << '\n';
  std::cout << "Set B: ";
  std::copy(B.begin(), B.end(), out);
  std::cout << '\n';

  std::cout << "Union of A and B:\n";
  std::set_union(A.begin(), A.end(), B.begin(), B.end(), out);
  std::cout << '\n';

  std::cout << "Intersection of A and B:\n";
  std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
  std::cout << '\n';

  std::cout << "Difference of A and B:\n";
  std::set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
  std::cout << '\n';

  std::set<std::string> C;
  std::cout << "Set C: ";
  std::set_union(
    A.begin(), A.end(), B.begin(), B.end(),
    std::insert_iterator<std::set<std::string>>(C, C.begin())
  );
  std::copy(C.begin(), C.end(), out);
  std::cout << '\n';
  
  std::string s3("grungy");
  C.insert(s3); // Automaticly finds the place for new object
  std::cout << "Set C after insertion:\n";
  std::copy(C.begin(), C.end(), out);
  std::cout << '\n';
  
  std::cout << "Showing a range:\n";
  std::copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
  std::cout << '\n';

  return 0;
}
