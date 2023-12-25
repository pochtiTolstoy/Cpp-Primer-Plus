#include <iostream>
#include <cstring>
#include "cow.h"

Cow::Cow() {
  name[0] = '\0';
  hobby = new char[1];
  hobby[0] = '\0';
  weight = 0;
}

Cow::Cow(const char* nm, const char* ho, double we) {
  strncpy(name, nm, SIZE); 
  name[SIZE - 1] = '\0';
  hobby = new char[strlen(ho) + 1];
  strcpy(hobby, ho);
  weight = we;
}

Cow::Cow(const Cow& c) {
  strcpy(name, c.name);
  hobby = new char[strlen(c.hobby) + 1];
  strcpy(hobby, c.hobby);
  weight = c.weight;
}

Cow::~Cow() {
  delete[] hobby;
}

Cow& Cow::operator=(const Cow& c) {
  if (this == &c)
    return *this;
  delete[] hobby;
  hobby = new char[strlen(c.hobby) + 1];
  strcpy(hobby, c.hobby);
  strcpy(name, c.name);
  weight = c.weight;
  return *this;
}

void Cow::ShowCow(void) const {
  std::cout << "Name: "   << name << std::endl
            << "Hobby: "  << hobby << std::endl
            << "Weight: " << weight << std::endl;
}
