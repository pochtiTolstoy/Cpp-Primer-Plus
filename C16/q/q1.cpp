//#include <cstring>
#include <iostream>
#include <string>
/*
class RQ1 {
private:
  char* st;
public:
  RQ1() { st = new char[1]; strcpy(st, ""); }
  RQ1(const char* s) {
    st = new char[strlen(s) + 1]; 
    strcpy(st, s); 
  }
  RQ1(const RQ1& rq) {
    st = new char[strlen(rq.st) + 1];
    strcpy(st, rq.st);
  }
  ~RQ1() { delete[] st };
  RQ& operator=(const RQ& rq);
};
*/

// using string
class RQ1 {
private:
  std::string st;
public:
  RQ1(): st("") {}
  RQ1(const std::string& s): st(s) {}
  RQ1(const RQ1& rq) = default;
  ~RQ1() {}
  RQ1& operator=(const RQ1& rq) = default;
  const std::string& get_st() const { return st; }
};

std::ostream& operator<<(std::ostream& os, const RQ1& rq) {
  os << rq.get_st();
  return os;
}

int main() {
  RQ1 s1("Hello ");
  RQ1 s2 = s1;
  RQ1 s3("World");
  std::cout << s1 << s2 << s3 << '\n';
  return 0;
}
