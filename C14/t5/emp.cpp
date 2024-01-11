#include "emp.h"

// class abstr_emp
abstr_emp::abstr_emp()
  : fname("noname"), lname("noname"), job("nojob") {}

abstr_emp::abstr_emp(
  const std::string& fn,
  const std::string& ln,
  const std::string& j
): fname(fn), lname(ln), job(j) {}

void abstr_emp::ShowAll() const {
  std::cout 
    << "First name: " << fname << '\n'
    << "Last name: "  << lname << '\n'
    << "Job: "        << job   << '\n';
}

void abstr_emp::SetAll() {
  std::cout << "Enter first name: ";
  std::cin >> fname;
  std::cout << "Enter last name: ";
  std::cin >> lname;
  std::cout << "Enter your job: ";
  std::cin >> job;
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& a) {
  os << "First name: " << a.fname << '\n'
     << "Last name: "  << a.lname << '\n'
     << "Job: "        << a.job   << '\n';
  return os;
}

abstr_emp::~abstr_emp() {}

// class employee: public abstr_emp
employee::employee(): abstr_emp() {}

employee::employee(
  const std::string& fn,
  const std::string& ln,
  const std::string& j
): abstr_emp(fn, ln, j) {}

void employee::ShowAll() const {
  abstr_emp::ShowAll();
}

void employee::SetAll() {
  abstr_emp::SetAll(); 
}

// class manager
manager::manager(): abstr_emp() {}

manager::manager(
  const std::string& fn,
  const std::string& ln,
  const std::string& j,
  int ico
): abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp& a, int ico): abstr_emp(a), inchargeof(ico) {}

manager::manager(const manager& other): abstr_emp(other), inchargeof(other.inchargeof) {}

void manager::ShowAll() const {
  abstr_emp::ShowAll();
  std::cout << "Ico: " << inchargeof << '\n';
}

void manager::SetAll() {
  abstr_emp::SetAll();
  std::cout << "Enter ico: ";
  std::cin >> inchargeof;
  std::cin.get();
}

// class fink
fink::fink(): abstr_emp() {}

fink::fink(
  const std::string& fn,
  const std::string& ln,
  const std::string& j,
  const std::string& r
): abstr_emp(fn, ln, j), reportsto(r) {}

fink::fink(
  const abstr_emp& a, 
  const std::string& r
): abstr_emp(a), reportsto(r) {}

fink::fink(const fink& f): abstr_emp(f), reportsto(f.reportsto) {}

void fink::ShowAll() const {
  abstr_emp::ShowAll();
  std::cout << "Rep: " << reportsto << '\n';
}

void fink::SetAll() {
  abstr_emp::SetAll();
  std::cout << "Enter repo: ";
  std::cin >> reportsto;
}

// class highfink
highfink::highfink(): abstr_emp(), manager(), fink() {}

highfink::highfink(
  const std::string& fn,
  const std::string& ln,
  const std::string& j,
  const std::string& r,
  int ico
): abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, r) {}

highfink::highfink(
  const abstr_emp& a,
  const std::string& r,
  int ico
): abstr_emp(a), manager(a, ico), fink(a, r) {}

highfink::highfink(const fink& f, int ico)
  : abstr_emp(f), manager(f, ico), fink(f) {}

highfink::highfink(const manager& m, const std::string& r)
  : abstr_emp(m), manager(m), fink(m, r) {}

highfink::highfink(const highfink& h)
  : abstr_emp(h), manager(h), fink(h) {}

void highfink::ShowAll() const {
  abstr_emp::ShowAll();
  std::cout << "Ico: " << InChargeOf() << '\n';
  std::cout << "Rep: " << ReportsTo() << '\n';
}

void highfink::SetAll() {
  abstr_emp::SetAll();
  std::cout << "Enter ico: ";
  std::cin >> InChargeOf();
  std::cin.get();
  std::cout << "Enter repo: ";
  std::cin >> ReportsTo();
}
