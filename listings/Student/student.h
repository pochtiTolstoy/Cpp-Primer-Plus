#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <valarray>

class Student {
private:
  typedef std::valarray<double> ArrayDb;
  std::string name;
  ArrayDb scores;
  std::ostream& arr_out(std::ostream& os) const;
public:
  Student() : name("Null Student"), scores() {}
  explicit Student(const std::string& s) 
    : name(s), scores() {} // zero elements in valarray, default constructor
  // Copy constructor of std::string
  Student(const std::string& s, int n)
    : name(s), scores(n) {} // n elements in valarray
  Student(const std::string& s, const ArrayDb& a)
    : name(s), scores(a) {} // Copy constructor of valarray
  Student(const char* str, const double* pd, int n)
    : name(str), scores(pd, n) {} // Copy first n elems from pd,
    // constructor from const char* to std::string
  ~Student() {}
  double Average() const;
  const std::string& Name() const;
  // returns non-const lvalue
  double& operator[](int i); // calls from only non-constant object
  // returns rvalue
  double operator[](int i) const; // overloaded by const. Can be called
  // from constant object

  // friends
  friend std::istream& operator>>(std::istream& is, Student& stu); // one word
  friend std::istream& getline(std::istream& is, Student& stu); // one line
  friend std::ostream& operator<<(std::ostream& os, const Student& stu);
};

#endif /* STUDENT_H_ */
