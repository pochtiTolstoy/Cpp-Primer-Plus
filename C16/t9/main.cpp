#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <typename Container>
void show_container(const Container& cont);

template <typename Container>
void show_only_part_container(const Container& cont);

int main() {
  const int SIZE = 10'000'000;    // SIZE of containers
  const int MOD = 1'000'000'000;
  std::srand(std::time(0));
  clock_t start = clock();
  std::vector<int> vi0(SIZE);     // Source vector
  for (auto& x: vi0) x = rand() % MOD;

  // New containers from source vector
  std::vector<int> vi = vi0;
  std::list<int> li(vi0.begin(), vi0.end());
  clock_t end = clock();
  double diff = static_cast<double>(end - start) / CLOCKS_PER_SEC;
  std::cout << "Preparing data: " << diff << '\n';

  // Print start data
  std::cout << "\nSource vector vi0:\n";
  show_only_part_container(vi0);
  std::cout << "\nCopy vector vi:\n";
  show_only_part_container(vi);
  std::cout << "\nList structure li:\n";
  show_only_part_container(li);

  // VECTOR TEST
  std::cout << "\nLet's test sort vi and li: " << SIZE << " elems.\n";
  start = clock();
  std::sort(vi.begin(), vi.end());
  end = clock();
  double vec_diff = static_cast<double>(end - start) / CLOCKS_PER_SEC;
  std::cout << "-- Sorted vi:\n";
  show_only_part_container(vi);
  
  // LIST TEST
  start = clock();
  li.sort();
  end = clock();
  double list_diff = static_cast<double>(end - start) / CLOCKS_PER_SEC;
  std::cout << "-- Sorted li:\n";
  show_only_part_container(li);

  // LIST TO VECTOR TEST:
  std::cout << "\nWhat if we copy list into vector for "
    "sorting and then copy it back?\n";
  // Copy source vector to list
  std::copy(vi0.begin(), vi0.end(), li.begin());
  //std::cout << "-- Old list:\n";
  //show_only_part_container(li);
  start = clock();
  std::vector<int> temp(li.begin(), li.end());     // 1. Copy list to vector
  std::sort(temp.begin(), temp.end());             // 2. STL sort of vector
  std::copy(temp.begin(), temp.end(), li.begin()); // 3. Copy back
  end = clock();
  double l2v_diff = static_cast<double>(end - start) / CLOCKS_PER_SEC;
  std::cout << "-- Sorted li again:\n";
  show_only_part_container(li);

  std::cout << "-- Time of STL sort for vector: " << vec_diff << '\n';
  std::cout << "-- Time of method sort for list: " << list_diff << '\n';
  std::cout << "-- Time of list to vector method: " << l2v_diff << '\n';

  return 0;
}

template <typename Container>
void show_container(const Container& cont) {
  char elem_in_row = 0;
  std::cout << "[";
  for (auto const& x: cont) {
    if (elem_in_row % 6 == 0) std::cout << '\n';
    std::cout << ' ' << x;
    elem_in_row = (elem_in_row + 1) % 6;
  }
  std::cout << "\n]\n";
}

template <typename Container>
void show_only_part_container(const Container& cont) {
  if (cont.size() <= 100) show_container(cont);
  char elem_in_row = 0;
  auto iter = cont.begin();
  int counter = 0;

  std::cout << "[";
  while (iter != cont.end()){
    if (counter == cont.size() - 50) {
      std::cout << "\n.............................................................";
      elem_in_row = 0;
    }
    if (counter < 50 || counter >= cont.size() - 50) {
      if (elem_in_row % 6 == 0) std::cout << '\n';
      std::cout << ' ' << *iter;
      elem_in_row = (elem_in_row + 1) % 6;
    }
    ++iter;
    ++counter;
  }
  std::cout << "\n]\n";
}
