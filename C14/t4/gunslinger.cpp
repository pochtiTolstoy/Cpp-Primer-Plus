#include "gunslinger.h"

Gunslinger::Gunslinger(): Person(), time_(0.0), notch_(0) {}

Gunslinger::Gunslinger(double t, int n, const std::string& s1, const std::string& s2)
  : Person(s1, s2), time_(t), notch_(n) {}

Gunslinger::~Gunslinger() {}

void Gunslinger::Show() const {
  Person::Show();
  std::cout 
    << "Time: "  << time_ << '\n'
    << "Notch: " << notch_ << '\n';
}

void Gunslinger::Set() {
  Person::Data();
  Data();
}

void Gunslinger::Data() {
  std::cout << "Enter time: ";
  std::cin >> time_;
  std::cout << "Enter notch: ";
  std::cin >> notch_;
}
