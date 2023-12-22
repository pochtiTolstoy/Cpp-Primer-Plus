#include "compl.h"

//CLASS FUNCTIONS
Complex::Complex() {
  re = im = 0.0;
}

Complex::Complex(double re, double im) {
  this->re = re;
  this->im = im;
}

void Complex::set_re(double re) {
  this->re = re;
}

void Complex::set_im(double im) {
  this->im = im;
}

Complex Complex::operator~() const {
  return Complex(this->re, -(this->im));
}

Complex Complex::operator+(const Complex& c) const {
  return Complex(re + c.re, im + c.im);
}

Complex Complex::operator-(const Complex& c) const {
  return Complex(re - c.re, im - c.im);
}

Complex Complex::operator*(const Complex& c) const {
  double re_part = re * c.re - im * c.im;
  double im_part = re * c.im + c.re * im;
  return Complex(re_part, im_part);
}

Complex Complex::operator*(double n) const {
  return Complex(re * n, im * n); 
}

//FRIEND FUNCTIONS
Complex operator*(double n, const Complex& c) {
  return Complex(c.re * n, c.im * n);
}

std::istream& operator>>(std::istream& is, Complex& c) {
  double re;
  double im;
  std::cout << "real: ";
  is >> re;
  if (is.fail())
    return is;
  std::cout << "complex: ";
  is >> im;
  if (is.fail())
    return is;
  c.set_re(re); 
  c.set_im(im); 
  return is;
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
  os << '(' << c.re << ',' << c.im << "i)";
  return os;
}
