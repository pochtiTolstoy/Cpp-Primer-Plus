// golf.h - для pe9-1.cpp
#ifndef GOLF_H_
#define GOLF_H_
/*
const int Len = 40; // внутреннее связывание
struct golf {
  char fullname[Len];
  int handicap;
};

static void clear_buffer(void);
static void free_io(void);
void setgolf(golf& g, const char* name, int hc);
int setgolf(golf& g);
void handicap(golf& g, int hc);
void showgolf(const golf& g);
*/

class Golf {
private:
  static const int Len = 40;
  char m_fullname[Len];
  int m_handicap;
public:
  Golf();
  Golf(const char* name, int hc); 
  int setgolf(void);
  void handicap(int hc);
  void showgolf(void) const;
};

static void clear_buffer(void);
static void free_io(void);

#endif /* GOLF_H_ */
