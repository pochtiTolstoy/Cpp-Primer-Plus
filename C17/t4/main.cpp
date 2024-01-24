#include <iostream>
#include <fstream>
#include <string>

template <typename StreamType>
void is_open_check(const StreamType&); 

int main(int argc, char* argv[]) {
  if (argc != 4) {
    std::cerr << "Error number arguments.\n";
    exit(EXIT_FAILURE);
  }
  std::ifstream in1(argv[1]);
  is_open_check(in1);
  std::ifstream in2(argv[2]);
  is_open_check(in2);
  std::ofstream out(argv[3]);
  is_open_check(out);

  std::string temp; 
  while (in1.peek() != EOF || in2.peek() != EOF) {
    if (std::getline(in1, temp)) out << temp;
    else if (std::getline(in2, temp)) out << temp;
    if (std::getline(in2, temp)) out << ' ' << temp;
    out << '\n';
  }

  in1.close();
  in2.close();
  out.close();
  return 0;
}

template <typename StreamType>
void is_open_check(const StreamType& file) {
  if (!file.is_open()) {
    std::cerr << "File error.\n";
    exit(EXIT_FAILURE);
  }
} 
