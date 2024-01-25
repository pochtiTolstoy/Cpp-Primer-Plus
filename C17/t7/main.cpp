#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>

// functor
class Store {
private:
  std::ofstream& fout_;
public:
  Store(std::ofstream& fout): fout_(fout) {}
  void operator()(const std::string& str) {
    size_t len = str.length();
    fout_.write(reinterpret_cast<char*>(&len), sizeof(std::size_t));
    fout_.write(str.data(), len);
  }
};

void ShowStr(const std::string&);
void GetStrs(std::ifstream&, std::vector<std::string>&);

int main() {
  std::vector<std::string> vostr; 
  std::string temp;

  std::cout << "Enter strings (empty line to quit):\n";
  while (std::getline(std::cin, temp) && temp[0] != '\0')
    vostr.push_back(temp);
  std::cout << "Here is your input.\n";
  for_each(vostr.begin(), vostr.end(), ShowStr);

  std::ofstream fout("strings.dat", std::ios_base::out 
    | std::ios_base::binary);
  for_each(vostr.begin(), vostr.end(), Store(fout));
  fout.close();

  std::vector<std::string> vistr;
  std::ifstream fin("strings.dat", std::ios_base::in 
    | std::ios_base::binary);
  if (!fin.is_open()) {
    std::cerr << "Could not open file for input.\n";
    exit(EXIT_FAILURE);
  }
  GetStrs(fin, vistr);
  std::cout << "\nHere are the strings read from the file:\n";
  for_each(vistr.begin(), vistr.end(), ShowStr);
  return 0;
}

void ShowStr(const std::string& str) {
  std::cout << str << '\n';
}

void GetStrs(std::ifstream& fin, std::vector<std::string>& vec) {
  size_t len;
  char ch;
  std::string temp;
  while (fin.read(reinterpret_cast<char*>(&len), sizeof(std::size_t))) {
    temp = "";
    for (size_t i = 0; i < len; ++i) {
      fin.read(reinterpret_cast<char*>(&ch), sizeof(char));
      temp += ch;
    }
    vec.push_back(temp);
  }
}
