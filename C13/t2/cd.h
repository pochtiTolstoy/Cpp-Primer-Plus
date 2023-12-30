#ifndef CD_H_
#define CD_H_

class Cd {
private:
  //char performer[50];
  //char label[20];
  char* performer;
  char* label;
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

#endif /* CD_H_ */
