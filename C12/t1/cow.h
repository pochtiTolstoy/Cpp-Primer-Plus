#ifndef COW_H_
#define COW_H_

class Cow {
private:
  static const int SIZE = 20;
  char name[SIZE];
  char* hobby;
  double weight;
public:
  Cow();
  Cow(const char*, const char*, double);
  Cow(const Cow&);
  ~Cow();
  Cow& operator=(const Cow&);
  void ShowCow(void) const;
};

#endif /* COW_H_ */
