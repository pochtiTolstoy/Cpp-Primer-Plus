#ifndef CLASSIC_H_
#define CLASSIC_H_

#include "cd.h"

class Classic : public Cd {
private:
  char name[65];
public:
  Classic();
  Classic(const Classic&);
  Classic(const char*, const char*, const char*, int, double);
  virtual ~Classic();
  virtual void Report() const;
  Classic& operator=(const Classic&);
};

#endif /* CLASSIC_H_ */
