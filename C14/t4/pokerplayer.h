#ifndef POKERPLAYER_H_
#define POKERPLAYER_H_
#include <cstdlib>
#include <ctime>
#include "person.h"
#include "card.h"

class Pokerplayer: virtual public Person {
private:
  Card card_;
protected:
  void Data() override;
public:
  Pokerplayer(); 
  Pokerplayer(int, const std::string&, const std::string&);
  Pokerplayer(const Card&, const std::string&, const std::string&);
  virtual ~Pokerplayer();
  void Show_Card() const;
  Card Draw() const;
  void Set() override;
};

#endif /* POKERPLAYER_H_ */
