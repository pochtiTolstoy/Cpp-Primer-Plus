#ifndef STRING1_H_
#define STRING1_H_

#include <iostream>
#include <cstring>
class String {
private:
  char* str;
  int len;
  static int num_strings;
  static const int CINLIM = 80;
public:
  String(const char* s);
  String();
  String(const String&);
  ~String();
  int length() const { return len; }
  String& stringlow();
  String& stringup();
  int has(char) const;

  String& operator=(const String&);
  String& operator=(const char*);
  char& operator[](int i);
  const char& operator[](int i) const;

  friend String operator+(const String&, const String&);
  friend bool operator<(const String&, const String&);
  friend bool operator<=(const String&, const String&);
  friend bool operator>(const String&, const String&);
  friend bool operator>=(const String&, const String&);
  friend bool operator==(const String&, const String&);
  friend bool operator!=(const String&, const String&);
  friend std::ostream& operator<<(std::ostream&, const String&);
  friend std::istream& operator>>(std::istream&, String&);

  static int HowMany();
};

inline bool operator<(const String& st1, const String& st2) {
  return (std::strcmp(st1.str, st2.str) < 0);
}

inline bool operator>(const String& st1, const String& st2) {
  return st2 < st1;
}

inline bool operator<=(const String& st1, const String& st2) {
  return !(st1 > st2);
}

inline bool operator>=(const String& st1, const String& st2) {
  return !(st1 < st2);
}

inline bool operator==(const String& st1, const String& st2) {
  return !(st1 < st2 || st1 > st2);
}

inline bool operator!=(const String& st1, const String& st2) {
  return !(st1 == st2);
}


#endif /* STRING1_H_ */
