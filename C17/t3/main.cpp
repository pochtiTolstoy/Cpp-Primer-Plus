#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Error number of arguments.\n";
    exit(EXIT_FAILURE);
  }
  std::ifstream fin(argv[1]);
  if (!fin.is_open()) {
    std::cerr << "File error.\n";
    exit(EXIT_FAILURE);
  }

  std::ofstream fout(argv[2]);
  if (!fout.is_open()) {
    std::cerr << "File error.\n";
    exit(EXIT_FAILURE);
  }
  char ch;
  while (fin.get(ch)) {
    fout << ch;
  }
  return 0;
}
