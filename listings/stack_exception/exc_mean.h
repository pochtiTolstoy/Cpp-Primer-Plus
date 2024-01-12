#include <iostream>

class bad_hmean {
private:
  double v1;
  double v2;
public:
  bad_hmean(double a = 0, double b = 0): v1(a), v2(b) {}
  void msg() const;
};

inline void bad_hmean::msg() const {
  std::cout << "hmean(" << v1 << ", " << v2 << "): "
    << "invaild arguments: a = -b\n";
}

class bad_gmean {
private:
  double v1;
  double v2;
public:
  bad_gmean(double a = 0, double b = 0): v1(a), v2(b) {}
  double get_v1() const { return v1; }
  double get_v2() const { return v2; }
  const char* msg() const;
};

inline const char* bad_gmean::msg() const {
  return "gmean() arguments should be >= 0\n";
}
