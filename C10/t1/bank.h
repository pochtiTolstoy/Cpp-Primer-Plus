#ifndef BANK_H_
#define BANK_H_

class Bank {
private:
  enum { SIZE = 65 };
  char m_name[SIZE];
  char m_number[SIZE];
  double m_balance;
public:
  Bank();
  Bank(const char*, const char*, double balance = 0.0);
  void show_data(void) const;
  void add_money(double);
  bool withdraw_money(double);
};

#endif /* BANK_H_ */
