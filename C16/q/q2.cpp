#include <cctype>
#include <iostream>
#include <string>
#include <functional>

void ToUpper(std::string& st);
//char toupper_ch(char ch);

int main() {
  std::string st = "Hello world!";
  std::cout << st << '\n';
  ToUpper(st);
  std::cout << st << '\n';
  return 0;
}

void ToUpper(std::string& st) {
  std::transform(st.begin(), st.end(), st.begin(), /*toupper_ch*/ toupper);
}

//char toupper_ch(char ch) { return toupper(ch); }
