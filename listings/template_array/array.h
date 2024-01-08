#ifndef ARRAY_H_
#define ARRAY_H_
#include <iostream>
#include <cstdlib>
template <class T, int n>
class Array {
private:
  T arr_[n];
public:
  Array() {};
  explicit Array(const T& v);
  virtual T& operator[](int i);
  virtual T operator[](int i) const;
  //virtual Array& operator=(const Array&);
};

template <class T, int n>
Array<T, n>::Array(const T& v) {
  for (int i = 0; i < n; ++i)
    arr_[i] = v;
}

template <class T, int n>
T& Array<T, n>::operator[](int i) {
  if (i < 0 || i >= n) {
    std::cerr << "Error in array limits: " << i
              << " is out of range\n";
    std::exit(EXIT_FAILURE);
  }
  return arr_[i];
}

template <class T, int n>
T Array<T, n>::operator[](int i) const {
  if (i < 0 || i >= n) {
    std::cerr << "Error in array limits: " << i
              << " is out of range\n";
    std::exit(EXIT_FAILURE);
  }
  return arr_[i];
}

/*
template <class T, int n>
Array<T, n>& Array<T, n>::operator=(const Array<T, n>& other) {
  for (int i = 0; i < n; ++i)
    arr_[i] = other.arr_[i];
  return *this;
}
*/

#endif
