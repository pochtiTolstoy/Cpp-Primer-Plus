#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Error number of arguments.\n";
    exit(EXIT_FAILURE);
  }
  std::ofstream fout(argv[1]);
  if (!fout.is_open()) {
    std::cerr << "Can't open the file.\n";
    exit(EXIT_FAILURE);
  }
  int ch;
  while ((ch = std::cin.get()) != EOF) {
    fout << static_cast<char>(ch);
  }
  fout.close();
  return 0;
}
