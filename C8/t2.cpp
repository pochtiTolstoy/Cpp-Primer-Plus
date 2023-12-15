#include <iostream>
#include <cstring>

const int SIZE = 65;

struct CandyBar {
  char name[SIZE];
  double weight;
  int kalories;
};

void fill(CandyBar&, 
          const char* name = "Millennium Munch", 
          double weight = 2.85, 
          int kalories  = 350);
void show_bar(const CandyBar&);

int main() {
  CandyBar b1;
  fill(b1, "Charlie!");
  show_bar(b1);
  fill(b1);
  show_bar(b1);
  fill(b1, "Mars", 3.0, 120);
  show_bar(b1);

  return 0;
}


void fill(CandyBar& b, const char* name, double weight, int kalories) {
  strncpy(b.name, name, SIZE);  
  b.name[SIZE - 1] = '\0';
  b.weight = weight;
  b.kalories = kalories;
}

void show_bar(const CandyBar& b) {
  std::cout << "Name: "     << b.name     << std::endl
            << "Weight: "   << b.weight   << std::endl
            << "Kalories: " << b.kalories << std::endl;
  std::cout << std::endl;
}
