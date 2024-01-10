#include "pokerplayer.h"

Pokerplayer::Pokerplayer(): Person(), card_() {}

Pokerplayer::Pokerplayer(int n, const std::string& s1, const std::string& s2)
  : Person(s1, s2), card_(n) {}

Pokerplayer::Pokerplayer(const Card& c, const std::string& s1, const std::string& s2)
  : Person(s1, s2), card_(c) {}

Pokerplayer::~Pokerplayer() {}

void Pokerplayer::Show_Card() const {
  card_.Show();
}

Card Pokerplayer::Draw() const {
  std::srand(std::time(0));
  return Card(rand() % 52 + 1);
}

void Pokerplayer::Set() {
  Person::Data();
  Data();
}

void Pokerplayer::Data() {
  std::cout << "Enter card number: ";
  int num;
  std::cin >> num;
  card_ = Card(num);
}
