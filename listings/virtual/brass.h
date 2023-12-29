#ifndef BRASS_H_
#define BRASS_H_
#include <string>

class Brass { // Базовый класс
private:
  std::string fullName;
  long acctNum;
  double balance;
public:
  // Конструктор + по умолчанию
  Brass(
    const std::string& s = "Nullbody",
    long an = -1,
    double bal = 0.0
  );
  void Deposit(double amt);
  virtual void Withdraw(double amt); // виртуальная функция, будет переопределена
  double Balance() const;
  virtual void ViewAcct() const; // виртуальная функция, будет пкркопределена
  virtual ~Brass() {} // Деструктор базового класса должен быть виртуальным
  // чтобы ссылка базового типа, указывающая на производный класс, смогла 
  // сначала удалить произодный класс, а потом базовый. Иначе будет удалён только
  // базовый класс.
};

class BrassPlus : public Brass { // открытое наследование
private:
  double maxLoan;
  double rate;
  double owesBank;
public:
  BrassPlus(
    const std::string& s = "Nullbody",
    long an = -1,
    double bal = 0.0,
    double ml = 500,
    double r = 0.11125
  );
  // конструктор от базового объекта и параметров
  BrassPlus(
    const Brass& ba, 
    double ml = 500, 
    double r = 0.11125
  );
  virtual void ViewAcct() const;
  virtual void Withdraw(double amt);
  void ResetMax(double m) { maxLoan = m; }
  void ResetRate(double r) { rate = r; }
  void ResetOwes() { owesBank = 0; }
};

#endif /* BRASS_H_ */
