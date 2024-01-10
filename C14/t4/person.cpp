#include "person.h"

Person::Person()
  : fname_("noname"), lname_("noname") {}

Person::Person(const std::string& s1, const std::string& s2)
  : fname_(s1), lname_(s2) {}

Person::~Person() {}

void Person::Show() const {
  std::cout 
    << "First name: " << fname_ << '\n'
    << "Last name: "  << lname_ << '\n';
}

void Person::Set() {
  Data();
}

void Person::Data() {
  std::cout << "Enter first name: ";
  std::cin >> fname_;
  std::cout << "Enter last name: ";
  std::cin >> lname_;
}
