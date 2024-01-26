#include "cpmv.h"

Cpmv::Cpmv(): pi(new Info) {
  std::cout << "Cpmv::Default constructor.\n";
  pi->qcode = "empty_data";
  pi->zcode = "empty_data";
}

Cpmv::Cpmv(const std::string& q, const std::string& z)
  : pi(new Info) {
  std::cout << "Cpmv::String constructor.\n";
  pi->qcode = q;
  pi->zcode = z;
}

Cpmv::Cpmv(const Cpmv& cp): pi(new Info) {
  std::cout << "Cpmv::Copy constructor.\n";
  pi->qcode = cp.pi->qcode;
  pi->zcode = cp.pi->zcode;
}

Cpmv::Cpmv(Cpmv&& mv): pi(mv.pi) {
  std::cout << "Cpmv::Move constructor.\n";
  mv.pi = nullptr; 
}

Cpmv::~Cpmv() {
  std::cout << "Cpmv::Destructor.\n";
  delete pi;
}

Cpmv& Cpmv::operator=(const Cpmv& cp) {
  std::cout << "Cpmv::Copy operator=.\n";
  if (this == &cp)
    return *this;
  delete pi;
  pi = new Info;
  pi->qcode = cp.pi->qcode;
  pi->zcode = cp.pi->zcode;
  return *this;
}

Cpmv& Cpmv::operator=(Cpmv&& mv) {
  std::cout << "Cpmv::Move operator=.\n";
  if (this == &mv)
    return *this;
  delete pi;
  pi = mv.pi;
  mv.pi = nullptr;
  return *this;
}

Cpmv Cpmv::operator+(const Cpmv& obj) const {
  std::cout << "Cpmv::operator+.\n";
  return Cpmv(pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode);
}

void Cpmv::Display() const {
  std::cout << "Cpmv::Display:\n";
  std::cout << "Qcode: " << pi->qcode << '\n';
  std::cout << "Zcode: " << pi->zcode << '\n';
}
