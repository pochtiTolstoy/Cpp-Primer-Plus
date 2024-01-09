#include "worker.h"
#include <iostream>

// Worker defenition
Worker::~Worker() { /*std::cout << "I am Destructor!\n";*/ }
void Worker::Data() const {
  std::cout << "Name: " << fullname << '\n';
  std::cout << "Employee ID: " << id << '\n';
}
void Worker::Get() {
  std::getline(std::cin, fullname);
  std::cout << "Enter worker's ID: ";
  std::cin >> id;
  while (std::cin.get() != '\n')
    continue;
}

// Waiter methods
void Waiter::Set() {
  std::cout << "Enter waiter's name: ";
  Worker::Get();
  Get();
}
void Waiter::Show() const {
  std::cout << "Category: waiter\n";
  Worker::Data();
  Data();
}
void Waiter::Data() const {
  std::cout << "Panache rating: " << panache << '\n';
}
void Waiter::Get() {
  std::cout << "Enter waiter's panache rating: ";
  std::cin >> panache;
  while (std::cin.get() != '\n')
    continue;
}

// Singer methods
const char* Singer::pv[Singer::Vtypes] = { 
  "other",
  "alto",
  "contralto",
  "soprano",
  "bass",
  "baritone",
  "tenor"
};
void Singer::Set() {
  std::cout << "Enter singer's name: ";
  Worker::Get();
  Get();
}
void Singer::Show() const {
  std::cout << "Category: singer\n";
  Worker::Data();
  Data();
}
void Singer::Data() const {
  std::cout << "Vocal range: " << pv[voice] << '\n';
}
void Singer::Get() {
  std::cout << "Enter number for singer's vocal range:\n";
  int i;
  for (i = 0; i < Vtypes; ++i) {
    std::cout << i << ": " << pv[i] << " ";
    if (i % 4 == 3) std::cout << '\n';
  }
  if (i % 4 != 0) std::cout << '\n';
  std::cin >> voice;
  while (std::cin.get() != '\n')
    continue;
}

// SingingWaiter methods
void SingingWaiter::Data() const {
  Singer::Data();
  Waiter::Data();
}
void SingingWaiter::Get() {
  Waiter::Get();
  Singer::Get();
}
void SingingWaiter::Set() {
  std::cout << "Enter siging waiter's name: ";
  Worker::Get();
  Get();
}
void SingingWaiter::Show() const {
  std::cout << "Category: singing waiter\n";
  Worker::Data();
  Data();
}
