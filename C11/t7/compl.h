#ifndef COMPL_H_
#define COMPL_H_

#include <iostream>

class Complex {
private:
  double re;
  double im;
  void set_re(double re = 0.0);
  void set_im(double im = 0.0);
public:
  Complex();
  Complex(double re, double im = 0.0);
  
  Complex operator~() const;
  Complex operator+(const Complex& c) const;
  Complex operator-(const Complex& c) const;
  Complex operator*(const Complex& c) const;
  Complex operator*(double n) const;

  friend Complex operator*(double n, const Complex& c);
  friend std::istream& operator>>(std::istream& is, Complex& c);
  friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

#endif /* COMPL_H_ */
