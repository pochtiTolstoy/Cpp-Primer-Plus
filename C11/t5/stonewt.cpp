#include <iostream>
#include "stonewt.h"

// Конструктор от double, может делать неявное преобразование
// Stonewt a = 10;
Stonewt::Stonewt(double lbs, Mode form) {
  mode = form;
  stone = int (lbs) / Lbs_per_stn;
  pds_left = int (lbs) % Lbs_per_stn + lbs - int (lbs);
  pounds = lbs;
}

//Конструктор от int и double
Stonewt::Stonewt(int stn, double lbs, Mode form) {
  mode = form;
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

void Stonewt::lbs_mode(void) {
  mode = LBS;  
}

void Stonewt::stn_mode(void) {
  mode = STN;
}

Stonewt& Stonewt::operator=(const Stonewt& st) {
  stone = st.stone;
  pds_left = st.pds_left;
  pounds = st.pounds;
  return *this;
}

Stonewt Stonewt::operator*(double n) const {
  return Stonewt(pounds * n);
}

Stonewt Stonewt::operator+(const Stonewt& st) const {
  return Stonewt(pounds + st.pounds);
}

Stonewt Stonewt::operator+(double pnd) const {
  return Stonewt(pounds + pnd);
}

Stonewt Stonewt::operator-(const Stonewt& st) const {
  return Stonewt(pounds - st.pounds);
}

Stonewt Stonewt::operator-(double pnd) const {
  return Stonewt(pounds - pnd);
}

std::ostream& operator<<(std::ostream& os, const Stonewt& st) {
  if (st.mode == Stonewt::LBS)
    std::cout << st.pounds << " pounds";
  else if (st.mode == Stonewt::STN)
    std::cout << st.stone << " stones, " << st.pds_left << " pounds";
  else
    std::cout << "Incorrect mode, should be LBS or STN.\n";
  return os;
}

Stonewt operator*(double n, const Stonewt& st) {
  return Stonewt(st.pounds * n);
}

Stonewt operator+(double pnd, const Stonewt& st) {
  return Stonewt(st.pounds + pnd);
}

Stonewt operator-(double pnd, const Stonewt& st) {
  return Stonewt(pnd - st.pounds);
}
