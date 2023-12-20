#include <iostream>
#include "stonewt.h"

// Конструктор от double, может делать неявное преобразование
// Stonewt a = 10;
Stonewt::Stonewt(double lbs) {
  stone = int (lbs) / Lbs_per_stn;
  pds_left = int (lbs) % Lbs_per_stn + lbs - int (lbs);
  pounds = lbs;
}

//Конструктор от int и double
Stonewt::Stonewt(int stn, double lbs) {
  stone = stn;
  pds_left = lbs;
  pounds = stn * Lbs_per_stn + lbs;
}

//Конструктор по умолчанию
Stonewt::Stonewt() {
  stone = pounds = pds_left = 0;
}

//Деструктор
Stonewt::~Stonewt() {}

//const метод
void Stonewt::show_stn() const {
  std::cout << stone << " stone, " << pds_left << " pounds\n";
}

void Stonewt::show_lbs() const {
  std::cout << pounds << " pounds\n";
}

Stonewt Stonewt::operator*(double n) const {
  return Stonewt(pounds * n);
}

Stonewt operator*(double n, const Stonewt& st) {
  return st * n;
}
