#ifndef WINE_H_
#define WINE_H_

#include <iostream>
#include <valarray>
#include <string>
#include "Pair.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine: private std::string, private PairArray {
private:
  int year_;
public:
  Wine();
  Wine(const char*, int);
  Wine(const char*, int, int [], int []);
  void GetBottles();
  void Show() const;
  const std::string& Label() const;
  int sum() const;
};

#endif /* WINE_H_ */
