#ifndef PLORG_H_
#define PLORG_H_

class Plorg {
private:
  static const int SIZE = 20;
  char name[SIZE];
  int CI;
public:
  Plorg(const char* str = "Plorga");
  void change_CI(int num);
  void show_plorg(void) const;
};

#endif
