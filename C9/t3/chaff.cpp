#include <iostream>
#include <new>
#include "chaff.h"

// work with struct
void show_struct(const chaff& p) {
  std::cout << "Dross: " << p.dross << std::endl;
  std::cout << "Slag: " << p.slag << std::endl;
}

void show_data(const chaff* const data) {
  for (int i = 0; i < SIZE_A; ++i)
    show_struct(data[i]);
}

// work with memory buffer
char* create_buffer(void) {
  char* tmp = new char[SIZE_B];
  return tmp;
}

void delete_buffer(char* buf) {
  if (buf != nullptr)
    delete[] buf;
}

// work with array of structs
chaff* create_data(char* buf) {
  chaff* tmp = new (buf) chaff[SIZE_A];
  return tmp;
}

void collect_data(chaff* const data) {
  for (int i = 0; i < SIZE_A; ++i) {
    std::cout << "Chaff #" << i + 1 << ":\n";
    std::cout << "Enter a dross: ";
    if (!std::cin.getline(data[i].dross, SIZE_S))
      clear_io();
    std::cout << "Enter slag: ";
    while (!(std::cin >> data[i].slag)) {
      std::cout << "Please, enter an integer value: ";
      clear_io();
    }
    clear_buffer();
  }
}

// other work
void clear_buffer(void) {
  while (std::cin.get() != '\n')
    continue;
}
void clear_io(void) {
  std::cin.clear();
  clear_buffer();
}
