#include <iostream>
#include <cstring>
#include <cctype>

const std::string& str_upper(std::string&);

int main() {
  std::string str;
  std::cout << "Enter a string (q to quit): ";
  while (std::getline(std::cin, str) && str != "q") {
    std::cout << str_upper(str) << std::endl; 
    std::cout << "Next string (q to quit): ";
  }
  std::cout << "Bye.\n";

  return 0;
}

const std::string& str_upper(std::string& str) {
  for (char& c : str) 
    c = std::toupper(c);
  return str;
}
