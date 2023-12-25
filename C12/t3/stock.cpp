#include <cstring>
#include "stock.h"

Stock::Stock() {
  static const char* no_name = "no name";
  company = new char[strlen(no_name) + 1];
  std::strcpy(company, no_name);
  shares = 0;
  share_val = 0.0;
  total_val = 0.0;
}

Stock::Stock(const char* co, long n, double pr) {
  company = new char[strlen(co) + 1];
  std::strcpy(company, co);
  if (n < 0) {
    std::cout << "Number of shares can't be negative; "
              << company << " shares set to 0.\n";
    shares = 0;
  } else
    shares = n;
  share_val = pr;
  set_tot();
}

Stock::~Stock() {
  delete[] company;
}

void Stock::buy(long num, double price) {
  if (num < 0) {
    std::cout << "Number of shares purchased can't be negative. "
              << "Transatcion is aborted.\n";
  } else {
    shares += num;
    share_val = price;
    set_tot();
  }
}

void Stock::sell(long num, double price) {
  if (num < 0) {
    std::cout << "Number of shares sold can't be negative. "
              << "Transation is aborted.\n";
  } else if (num > shares) {
    std::cout << "You can't sell more than you have! "
              << "Transaction is aborted.\n";
  } else {
    shares -= num;
    share_val = price;
    set_tot();
  }
}

void Stock::update(double price) {
  share_val = price;
  set_tot();
}

std::ostream& operator<<(std::ostream& os, const Stock& s) {
  std::ios_base::fmtflags orig =
    os.setf(std::ios_base::fixed, std::ios_base::floatfield);
  std::streamsize prec = os.precision(3);
  os << "Company: " << s.company
     << " Shares: " << s.shares << '\n';
  os << " Share price: $" << s.share_val;
  os.precision(2);
  os << " Total worth: $" << s.total_val << '\n';
  os.setf(orig, std::ios_base::floatfield);
  os.precision(prec);
  return os;
}

const Stock& Stock::topval(const Stock& s) const {
  if (s.total_val > total_val)
    return s;
  else 
    return *this;
}
