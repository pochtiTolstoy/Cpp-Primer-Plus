#ifndef CD_H_
#define CD_H_

class Cd {
private:
  char performer[50];
  char label[20];
  int selections;
  double playtime;
public:
  Cd(); // конструктор по умолчанию
  Cd(const Cd&); // конструктор копирования
  Cd(const char*, const char*, int, double); 
  virtual ~Cd(); // деструктор
  virtual void Report() const; // метод класса
  Cd& operator=(const Cd&); // оператор присваивания
};

class Classic : public Cd {
private:
  char name[65];
public:
  Classic();
  Classic(const Classic&);
  Classic(const char*, const char*, const char*, int, double);
  virtual ~Classic();
  virtual void Report() const;
  Classic& operator=(const Classic&);
};

#endif /* CD_H_ */
