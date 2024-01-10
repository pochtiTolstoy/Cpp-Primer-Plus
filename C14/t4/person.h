#ifndef PERSON_H_
#define PERSON_H_
#include <iostream>
#include <string>

class Person {
private:
  std::string fname_;
  std::string lname_;
protected:
  virtual void Data();
public:
  Person();
  Person(const std::string&, const std::string&);
  virtual ~Person();
  virtual void Show() const;
  virtual void Set();
};

#endif /* PERSON_H_ */
