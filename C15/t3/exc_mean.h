#ifndef EXC_H_
#define EXC_H_
#include <iostream>
#include <stdexcept>

class bad_mean: public std::logic_error {
private:
  double a_;
  double b_;
public:
  bad_mean(): logic_error(""), a_(0.0), b_(0.0) {}
  bad_mean(double a, double b): logic_error(""), a_(a), b_(b) {}
  virtual void show_info() const noexcept;
protected:
  double getA() const { return a_; }
  double getB() const { return b_; }
};

void bad_mean::show_info() const noexcept {
  std::cout << "bad_mean::what(): exception\n"
    << "Values: " << getA() << ", " << getB() <<'\n';
}

class bad_hmean: public bad_mean {
public:
  bad_hmean(double a, double b): bad_mean(a, b) {}
  void show_info() const noexcept override;
};

void bad_hmean::show_info() const noexcept {
  std::cout << "bad_hmean::what(): exception\n"
    << "Values: " << getA() << ", " << getB() <<'\n';
}

class bad_gmean: public bad_mean {
public:
  bad_gmean(double a, double b): bad_mean(a, b) {}
  void show_info() const noexcept override;
};

void bad_gmean::show_info() const noexcept {
  std::cout << "bad_gmean::what(): exception\n"
    << "Values: " << getA() << ", " << getB() <<'\n';
}

#endif
