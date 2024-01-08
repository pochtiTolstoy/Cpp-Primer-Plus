#include "Wine.h"

Wine::Wine(): label_("noname"), year_(0), data_() {}

Wine::Wine(const char* l, int y): label_(l), year_(y), data_(ArrayInt(y), ArrayInt(y)) {}

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
  : label_(l), year_(y), data_(ArrayInt(yr, y), ArrayInt(bot, y)) {}

const std::string& Wine::Label() const { return label_; }

void Wine::GetBottles() {
  std::cout << "Enter " << label_ << " data for " << year_ << " year(s):\n";
  for (int i = 0; i < year_; ++i) {
    std::cout << "Enter year: ";
    std::cin >> data_.first()[i];
    std::cout << "Enter bottles for that year: ";
    std::cin >> data_.second()[i];
  }
  while (std::cin.get() != '\n')
    continue;
}

int Wine::sum() const { return data_.second().sum(); }

void Wine::Show() const {
  std::cout << "Wine: " << label_ << '\n';
  std::cout << "      Year   Bottles\n";
  for (int i = 0; i < year_; ++i) {
    std::cout << "      " << data_.first()[i]
              << "   "    << data_.second()[i] << '\n';
  }
}
