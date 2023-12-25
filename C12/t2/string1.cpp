#include <cctype>
#include "string1.h"

int String::num_strings = 0;

inline int String::HowMany() {
  return num_strings;
}

String::String(const char* s) {
  len = std::strlen(s);
  str = new char[len + 1];
  std::strcpy(str, s);
  ++num_strings;
}

String::String() {
  len = 0;
  str = new char[1];
  str[0] = '\0';
  ++num_strings;
}

String::String(const String& st) {
  ++num_strings;
  len = st.len;
  str = new char[len + 1];
  std::strcpy(str, st.str);
}

String::~String() {
  --num_strings;
  delete[] str;
}

String& String::stringlow() {
  for (int i = 0; i < len; ++i)
    str[i] = tolower(str[i]);
  return *this;
}

String& String::stringup() {
  for (int i = 0; i < len; ++i)
    str[i] = toupper(str[i]);
  return *this;
}

int String::has(char ch) const {
  int cnt = 0;
  for (int i = 0; i < len; ++i)
    str[i] == ch ? ++cnt: cnt;
  return cnt;
}

String& String::operator=(const String& st) {
  if (this == &st)
    return *this;
  delete[] str;
  len = st.len;
  str = new char[len + 1];
  std::strcpy(str, st.str);
  return *this;
}

String& String::operator=(const char* st) {
  delete[] str;
  len = std::strlen(st);
  str = new char[len + 1];
  std::strcpy(str, st);
  return *this;
}

char& String::operator[](int i) {
  return str[i];
}

const char& String::operator[](int i) const {
  return str[i];
}

String operator+(const String& st1, const String& st2) {
  int len = strlen(st1.str) + strlen(st2.str);
  char* res_str = new char[len + 1];
  std::strcpy(res_str, st1.str);
  std::strcpy(res_str + strlen(st1.str), st2.str);
  res_str[len] = '\0';

  String res(res_str);
  delete[] res_str;
  return res;
}

std::ostream& operator<<(std::ostream& os, const String& st) {
  os << st.str; 
  return os;
}

std::istream& operator>>(std::istream& is, String& st) {
  char temp[String::CINLIM];
  is.get(temp, String::CINLIM);
  if (is)
    st = temp;
  while (is && is.get() != '\n')
    continue;
  return is;
}
