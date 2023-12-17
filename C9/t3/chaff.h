// chaff.h -- for chaff.cpp
#ifndef CHAFF_H_
#define CHAFF_H_

const int SIZE_B = 1024;
const int SIZE_A = 2;
const int SIZE_S = 20;

struct chaff {
  char dross[SIZE_S];
  int slag;
};

void show_struct(const chaff&);
void show_data(const chaff* const data);

char* create_buffer(void);
void delete_buffer(char* buf);

chaff* create_data(char* buf);
void collect_data(chaff* const data);

void clear_io(void);
void clear_buffer(void);

#endif /* CHAFF_H_ */
