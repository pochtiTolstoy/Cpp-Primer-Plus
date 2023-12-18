#include <iostream>
#include <cstring>
#include "bank.h"

Bank::Bank() {
  m_name[0] = '\0';
  m_number[0] = '\0';
  m_balance = 0;
}

Bank::Bank(const char* name, const char* number, double balance) {
  strncpy(m_name, name, SIZE);
  m_name[SIZE - 1] = '\0';
  strncpy(m_number, number, SIZE);
  m_number[SIZE - 1] = '\0';
  m_balance = balance;
}

void Bank::show_data(void) const {
  std::cout << "Bank account:\n"
            << "Full name: " << m_name    << std::endl
            << "Code: "      << m_number  << std::endl
            << "Balance: "   << m_balance << "\n\n";
}

void Bank::add_money(double value) {
  m_balance += value;
}

bool Bank::withdraw_money(double value) {
  if (m_balance < value) {
    std::cout << "Error, balance can't be negative.\n";
    return false;
  }
  m_balance -= value;
  return true;
}
