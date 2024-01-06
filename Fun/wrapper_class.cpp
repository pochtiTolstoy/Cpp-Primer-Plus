#include <iostream>

class crd_x {
private:
  double x_;
public:
  explicit crd_x(double x = 0.0): x_(x) {}
  double get_x() const { return x_; }
  friend std::istream& operator>>(std::istream&, crd_x&);
};

class crd_y {
private:
  double y_;
public:
  explicit crd_y(double y = 0.0): y_(y) {}
  double get_y() const { return y_; }
  friend std::istream& operator>>(std::istream&, crd_y&);
};


std::ostream& operator<<(std::ostream& os, const crd_x& obj) {
  std::cout << obj.get_x();
  return os;
}

std::istream& operator>>(std::istream& is, crd_x& obj) {
  std::cin >> obj.x_;
  return is;
}

std::ostream& operator<<(std::ostream& os, const crd_y& obj) {
  std::cout << obj.get_y();
  return os;
}

std::istream& operator>>(std::istream& is, crd_y& obj) {
  std::cin >> obj.y_;
  return is;
}

void take_xy(crd_x x, crd_y y);

int main() {
  crd_x x(2.3);
  crd_y y;
  std::cout << "Enter one real value: ";
  std::cin >> y;
  std::cin.get();

  // Correct:
  take_xy(x, y); 
  take_xy(crd_x(8.9), y);
  take_xy(x, crd_y(-0.3));
  take_xy(crd_x(), crd_y());
  take_xy(crd_x(0.1), crd_y(-2.5));

  // Incorrect (CE):
  // take_xy(0, 1);
  // take_xy(0, y); 
  // take_xy(x, 0); 

  return 0;
}

void take_xy(crd_x x, crd_y y) {
  std::cout << "x: " << x << ", y: " << y << '\n';
}
