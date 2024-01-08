#ifndef WINE_H_
#define WINE_H_
#include <iostream>
#include <string>
#include <valarray>
#include "Pair.h"


class Wine {
private:
  typedef std::valarray<int> ArrayInt;
  typedef Pair<ArrayInt, ArrayInt> PairArray;
  std::string label_;
  int year_;
  PairArray data_;
public:
  Wine();
  Wine(const char* l, int y);
  Wine(const char* l, int y, const int yr[], const int bot[]);
  void GetBottles();
  const std::string& Label() const;
  int sum() const;
  void Show() const;
};

#endif /* WINE_H_ */
