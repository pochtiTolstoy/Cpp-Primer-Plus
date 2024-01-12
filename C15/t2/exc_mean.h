#ifndef EXC_H_
#define EXC_H_

#include <iostream>
#include <stdexcept>

class bad_hmean: public std::logic_error {
public:
  bad_hmean(): std::logic_error("") {}
  const char* what() const noexcept override;
};

inline const char* bad_hmean::what() const noexcept {
  return "hmean(): invalid arguments: a = -b\n";
}

class bad_gmean: public std::logic_error {
public:
  bad_gmean(): logic_error("") {}
  const char* what() const noexcept override;
};

inline const char* bad_gmean::what() const noexcept {
  return "gmean() arguments should be >= 0\n";
}

#endif
