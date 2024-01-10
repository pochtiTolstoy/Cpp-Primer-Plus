#ifndef GUNSLINGER_H_
#define GUNSLINGER_H_
#include "person.h"

class Gunslinger: virtual public Person {
private:
  double time_;
  int notch_;
protected:
  void Data() override;
public:
  Gunslinger();
  Gunslinger(double, int, const std::string&, const std::string&);
  virtual ~Gunslinger();
  double Draw() const { return time_; }
  void Show() const override;
  void Set() override;
};

#endif /* GUNSLINGER */
