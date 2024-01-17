#include <cctype>
#include <iostream>
#include <string>

bool is_palindrom(const std::string& st);

int main() {
  std::cout << is_palindrom("tot") << '\n';
  std::cout << is_palindrom("otto") << '\n';
  std::cout << is_palindrom("afofb") << '\n';
  std::cout << is_palindrom("Otto") << '\n';
  std::cout << is_palindrom("Madam, I'm Adam") << '\n';
  std::cout << is_palindrom("Madam, Ipi'm Adam") << '\n';
  std::cout << is_palindrom("MAdAm") << '\n';
  std::cout << is_palindrom("MAdAmt") << '\n';
  std::cout << is_palindrom("mAdAM") << '\n';
  std::cout << is_palindrom("ab,,,.,.,/.,/.,/.,/a") << '\n';
  std::cout << is_palindrom("a,,,.,.,/.   ,/.,/.,/ba") << '\n';
  return 0;
}

bool is_palindrom(const std::string& st) {
  static const int LetterShift = 'A' - 'a';
  auto i_begin = st.begin();
  auto i_end = st.end();
  auto mid = i_begin + st.size();
  while (i_begin != mid) {
    if (!isalpha(*i_begin)) {
      ++i_begin;
      continue;
    }
    if (!isalpha(*i_end)) {
      --i_end;
      continue;
    }
    if ((*i_begin - *i_end) % LetterShift != 0)
      return false;
    ++i_begin;
    --i_end;
  }
  return true;
}
