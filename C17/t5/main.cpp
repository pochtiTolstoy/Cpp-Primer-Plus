#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>
#include "person.h"

template <typename StreamType>
void is_open_check(const StreamType&);

void save_list_names_file(std::ofstream& fout, const std::set<std::string>& list);

int main() {
  const char* filename1 = "mat.dat";
  const char* filename2 = "pat.dat";
  const char* filename3 = "matnpat.dat";
  std::ifstream fin1(filename1);
  is_open_check(fin1);
  std::ifstream fin2(filename2);
  is_open_check(fin2);
  std::ofstream fout(filename3);
  is_open_check(fout);
  M m;
  P p;
  m.get_names_file(fin1);
  p.get_names_file(fin2);
  m.show_names();
  p.show_names();
  std::set<std::string> res = concatenate_lists(p, m);
  save_list_names_file(fout, res);
  //std::cout << "Data from set:\n";
  /*
  std::copy(
    res.begin(), res.end(),
    std::ostream_iterator<std::string, char>(std::cout, " ")
  );
  */
  fin1.close();
  fin2.close();
  fout.close();

  return 0;
}

template <typename StreamType>
void is_open_check(const StreamType& file) {
  if (!file.is_open()) {
    std::cerr << "Error. File is not open.\n";
    exit(EXIT_FAILURE);
  }
}

void save_list_names_file(std::ofstream& fout, const std::set<std::string>& list) {
  std::copy(
    list.begin(), list.end(),
    std::ostream_iterator<std::string, char>(fout, "\n")
  );
}
