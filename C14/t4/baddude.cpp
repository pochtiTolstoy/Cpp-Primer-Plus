#include "baddude.h"

Baddude::Baddude()
  : Person(), Gunslinger(), Pokerplayer() {}

Baddude::Baddude(
  double time, 
  int notch, 
  int num,
  const std::string& s1,
  const std::string& s2
): Person(s1, s2), Gunslinger(time, notch, s1, s2), Pokerplayer(num, s1, s2) {}

Baddude::Baddude(
  double time, 
  int notch, 
  const Card& c,
  const std::string& s1,
  const std::string& s2
): Person(s1, s2), Gunslinger(time, notch, s1, s2), Pokerplayer(c, s1, s2) {}

Baddude::Baddude(const std::string& s1, const std::string& s2)
  : Person(s1, s2), Gunslinger(0.0, 0, s1, s2), Pokerplayer(1, s1, s2) {}

Baddude::~Baddude() {}

double Baddude::Gdraw() const { return Gunslinger::Draw(); }

Card Baddude::Cdraw() const { return Pokerplayer::Draw(); }

void Baddude::Show() const {
  std::cout << "Show Baddude:\n";
  Gunslinger::Show(); 
  Pokerplayer::Show_Card();
}

void Baddude::Set() {
  Person::Data();  
  Gunslinger::Data();
  Pokerplayer::Data();
}

void Baddude::Data() {}
