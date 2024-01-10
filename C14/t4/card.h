#ifndef CARD_H_
#define CARD_H_
#include <iostream>
#include <string>

class Card {
private:
  static const int SSIZE = 4;
  static const char* Suits_[SSIZE];
  static const char* Faces_;
  std::string suit_;
  std::string face_;
public:
  explicit Card(int number = 1);
  Card(const std::string&, const std::string&);
  void Show() const;
};

#endif /* CARD_H_ */
