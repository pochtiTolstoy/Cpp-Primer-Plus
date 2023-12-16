// golf.h - для pe9-1.cpp
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
