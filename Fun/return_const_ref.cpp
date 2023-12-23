#include <iostream>

// Почему в перегруженном операторе присваивания нельзя вернуть const ref

class Car {
private:
  int number;
public:
  Car() {};
  Car(int n): number(n) {}
  void show_number(void);
  Car& operator=(const Car&);
};

void Car::show_number(void) {
  std::cout << "Number: " << number << std::endl;
}

Car& Car::operator=(const Car& car) {
  number = car.number;
  return *this;
}

int main() {
  Car c1(1);
  Car c2(2);
  Car c3(3);
  c3 = c2 = c1;
  Car& ref = c2 = c1;
  c3.show_number();
  return 0;
}
