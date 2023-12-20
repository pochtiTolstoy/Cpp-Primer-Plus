#include <cmath>
#include "vect.h"

namespace VECTOR {
  const double Rad_to_deg = 45.0 / atan(1.0);

  double Vector::set_mag() const {
    return std::sqrt(x * x + y * y);
  }
  double Vector::set_ang() const {
    if (x == 0.0 && y == 0.0)
      return 0.0;
    return std::atan2(y, x);
  }
  void Vector::set_x(double n1, double n2) {
    x = n1 * std::cos(n2 / Rad_to_deg);
  }
  void Vector::set_y(double n1, double n2) {
    y = n1 * std::sin(n2 / Rad_to_deg);
  }
  Vector::Vector() {
    x = y = 0.0;
    mode = RECT;
  }
  Vector::Vector(double n1, double n2, Mode form) {
    mode = form;
    if (form == RECT) {
      x = n1;
      y = n2;
    } else if (form == POL) {
      set_x(n1, n2);
      set_y(n1, n2);
    } else {
      std::cout << "Incorrect 3rd argument to Vector() -- ";
      std::cout << "vector set to 0\n";
      x = y = 0.0;
      mode = RECT;
    }
  }
  void Vector::reset(double n1, double n2, Mode form) {
    *this = Vector(n1, n2, form);
  }
  Vector::~Vector() {}
  void Vector::polar_mode() { mode = POL; }
  void Vector::rect_mode() { mode = RECT; }
  double Vector::magval() const { return set_mag(); } // public version of set_mag()
  double Vector::angval() const { return set_ang(); } // public version of set_ang()
  Vector Vector::operator+(const Vector& b) const {
    return Vector(x + b.x, y + b.y);
  }
  Vector Vector::operator-(const Vector& b) const {
    return Vector(x - b.x, y - b.y);
  }
  Vector Vector::operator-() const {
    return Vector(-x, -y);
  }
  Vector Vector::operator*(double n) const {
    return Vector(n * x, n * y);
  }
  Vector operator*(double n, const Vector& a) {
    return a * n; //operator*(double n) 
  }
  std::ostream& operator<<(std::ostream& os, const Vector& v) {
    if (v.mode == Vector::RECT)
      os << "(x,y) = (" << v.x << ", " << v.y << ")";
    else if (v.mode == Vector::POL) {
      os << "(m,a) = (" << v.set_mag() << ", "
         << v.set_ang() * Rad_to_deg << ")";
    } else
      os << "Vector object mode is invalid";
    return os;
  }
}
