#include "card.h"

const char* Card::Suits_[Card::SSIZE] = {
  "Hearts",
  "Diamonds",
  "Clubs",
  "Spades"
};

const char* Card::Faces_ = "A234567891JQK";

Card::Card(int number) {
  number = (number - 1) % 52;
  int suit = number / 13;
  int face = number % 13;
  suit_ = Card::Suits_[suit];
  face_ = Card::Faces_[face];
  if (face == 9) face_ += '0';
}

Card::Card(const std::string& s1, const std::string& s2)
  : suit_(s1), face_(s2) {}

void Card::Show() const {
  std::cout 
    << "Suit: " << suit_ << '\n'
    << "Face: " << face_ << '\n';
}
