#include <iostream>
#include "brass.h"

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

Brass::Brass(const std::string& s, long an, double bal) {
  fullName = s;
  acctNum = an;
  balance = bal;
}

void Brass::Deposit(double amt) {
  if (amt < 0) {
    std::cout << "Negative deposit not allowed; "
              << "deposit is cancelled.\n";
    return;
  }
  balance += amt;
}

void Brass::Withdraw(double amt) {
  format initialState = setFormat();
  precis prec = std::cout.precision(2);
  if (amt < 0) {
    std::cout << "Withdrawal amount must be positive; "
              << "withdrawal canceled.\n";
  } else if (amt <= balance)
    balance -= amt;
  else
    std::cout << "Withdrawal amount of $" << amt
              << " exceeds your balance.\n"
              << "Withdrawal canceled.\n";
  restore(initialState, prec);
}

double Brass::Balance() const { return balance; }

void Brass::ViewAcct() const {
  format initialState = setFormat();
  precis prec = std::cout.precision(2);
  std::cout << "Client: " << fullName << std::endl;
  std::cout << "Account Number: " << acctNum << std::endl;
  std::cout << "Balance: $" << balance << std::endl;
  restore(initialState, prec);
}

BrassPlus::BrassPlus(
  const std::string& s, 
  long an, double bal,
  double ml, double r
) : Brass(s, an, bal) { // Сначала должен быть создан объект базового класса
  maxLoan = ml;
  owesBank = 0.0;
  rate = r;
}

BrassPlus::BrassPlus(
  const Brass& ba,
  double ml, double r
) : Brass(ba) { // неявный конструктор копирования для базового класса
  maxLoan = ml;
  owesBank = 0.0;
  rate = r;
}

void BrassPlus::ViewAcct() const {
  format initialState = setFormat();
  precis prec = std::cout.precision(2);
  Brass::ViewAcct(); // this-> вызывает определение метода для базового класса,
  // используя операцию разрешения контекста
  std::cout << "Maximum loan: $" << maxLoan << std::endl;
  std::cout << "Owed to bank: $" << owesBank << std::endl;
  std::cout.precision(3);
  std::cout << "Loan Rate: " << 100 * rate << "%\n";
  restore(initialState, prec);
}

void BrassPlus::Withdraw(double amt) {
  format initialState = setFormat();
  precis prec = std::cout.precision(2);
  double bal = Balance();
  if (amt <= bal)
    Brass::Withdraw(amt); // вызов определения функции для базового класса
  else if (amt <= bal + maxLoan - owesBank) {
    double advance = amt - bal;
    owesBank += advance * (1.0 + rate);
    std::cout << "Bank advance: $" << advance << std::endl;
    std::cout << "Finance charge: $" << advance * rate << std::endl;
    Deposit(advance);
    Brass::Withdraw(amt);
  } else
    std::cout << "Credit limit exceeded. Transation cancelled.\n";
  restore(initialState, prec);
}

format setFormat() {
  return std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p) {
  std::cout.setf(f, std::ios_base::floatfield);
  std::cout.precision(p);
}
