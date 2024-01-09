#include "Wine.h"

Wine::Wine(): std::string(), PairArray(), year_(0) {}

Wine::Wine(const char* l, int y)
  : std::string(l), PairArray(ArrayInt(y), ArrayInt(y)), year_(y) {}

Wine::Wine(const char* l, int y, int yr[], int bot[])
  : std::string(l), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)), year_(y) {}

void Wine::GetBottles() {
  std::cout << "Enter " << dynamic_cast<const std::string&>(*this)
    << " data for " << year_ << " year(s):\n";
  for (int i = 0; i < year_; ++i) {
    std::cout << "Enter year: ";
    std::cin >> PairArray::first()[i];
    std::cout << "Enter bottles for that year: ";
    std::cin >> PairArray::second()[i];
  }
  while (std::cin.get() != '\n')
    continue;
}

void Wine::Show() const {
  std::cout << "Wine: " << dynamic_cast<const std::string&>(*this) << '\n';
  std::cout << "      Year   Bottles\n";
  for (int i = 0; i < year_; ++i) {
    std::cout << "      " << PairArray::first()[i] 
              << "   "    << PairArray::second()[i] << '\n';
  }
}

const std::string& Wine::Label() const { 
  return dynamic_cast<const std::string&>(*this);
}

int Wine::sum() const { return PairArray::second().sum(); }
