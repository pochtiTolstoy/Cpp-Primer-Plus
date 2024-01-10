#ifndef BADDUDE_H_
#define BADDUDE_H_
#include "pokerplayer.h"
#include "gunslinger.h"

class Baddude: public Gunslinger, public Pokerplayer {
protected:
  void Data() override;
public:
  Baddude();
  Baddude(double, int, int, const std::string&, const std::string&);
  Baddude(double, int, const Card&, const std::string&, const std::string&);
  Baddude(const std::string&, const std::string&);
  virtual ~Baddude();
  double Gdraw() const;
  Card Cdraw() const;
  void Show() const override;
  void Set() override;
};

#endif /* BADDUDE_H_ */
