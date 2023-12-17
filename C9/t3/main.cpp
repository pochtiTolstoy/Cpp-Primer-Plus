#include <iostream>
#include "chaff.h"

int main() {
  char* buffer = create_buffer(); 
  chaff* data = create_data(buffer);
  collect_data(data);
  show_data(data);
  delete_buffer(buffer);
  return 0;
}

