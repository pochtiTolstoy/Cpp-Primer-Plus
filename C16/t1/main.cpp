#include <iostream>
#include <string>

bool is_palindrome(const std::string&);

int main() {
  std::string st = "Otto";
  std::string st2 = "tot";
  std::string st3 = "madamimadam";
  std::cout << is_palindrome(st) << '\n';
  std::cout << is_palindrome(st2) << '\n';
  std::cout << is_palindrome(st3) << '\n';
  return 0;
}

bool is_palindrome(const std::string& st) {
  int len = st.size() / 2;
  auto i_end = st.end() - 1;
  for (auto i_begin = st.begin(); i_begin != st.begin() + len; ++i_begin, --i_end)
    if (*i_begin != *i_end)
      return false;
  return true;
}
