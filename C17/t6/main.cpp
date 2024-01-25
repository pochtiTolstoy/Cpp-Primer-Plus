#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include "emp.h"

void show_file(std::ifstream&);
inline void free_io();
inline void clear_buffer();

int main() {
  const char* file = "data.txt";
  std::ifstream fin(file);
  if (fin.is_open()) {
    std::cout << "Showing existing data file:\n";
    show_file(fin);
    fin.close();
  } else {
    std::cout << "There is no such file with name: "
      << file << '\n';
  }
  const int SIZE = 3;
  abstr_emp* arr[SIZE];
  char ch;
  int items = 0;
  for (int i = 0; i < SIZE; ++i) {
    std::cout << "Enter person type:\n";
    std::cout << "(e)mployee, (m)anager, (f)ink, (h)highfink, (q)uit: ";
    while (!(std::cin >> ch) || (strchr("emfhq", ch) == nullptr)) {
      free_io();
      std::cout << "Please, enter e, m, f, h or q: ";
    }
    free_io();
    if (ch == 'q') break;

    switch (ch) {
      case 'e':
        arr[i] = new employee;
        break;
      case 'm':
        arr[i] = new manager;
        break;
      case 'f':
        arr[i] = new fink;
        break;
      case 'h':
        arr[i] = new highfink;
        break;
      default: 
        std::cout << "Error. There is no such option: " << ch << '\n';
        exit(EXIT_FAILURE);
    }
    ++items;
    arr[i]->SetAll();
  }
  const int ITEMS = items;
  std::ofstream fout(file, std::ios_base::out | std::ios_base::app);
  for (int i = 0; i < ITEMS; ++i)
    arr[i]->WriteAll(fout);
  fout.close();

  fin.open(file);
  if (fin.is_open()) {
    std::cout << "Showing refreshed data in file:\n";
    show_file(fin);
    fin.close();
  } else {
    std::cout << "There is no such file with name: "
      << file << '\n';
  }

  // free allocated memory
  for (int i = 0; i < ITEMS; ++i)
    delete arr[i];
  return 0;
}

void show_file(std::ifstream& fin) {
  if (fin.peek() == std::ifstream::traits_type::eof()) {
    std::cout << "File is empty...\n";
    return;
  }
  std::vector<abstr_emp*> pts; 
  int class_type;
  abstr_emp* pt;
  while (fin >> class_type) {
    fin.get();
    switch (class_type) {
      case Employee: pt = new employee; break;
      case Manager:  pt = new manager;  break;
      case Fink:     pt = new fink;     break;
      case Highfink: pt = new highfink; break;
    }
    pt->GetAll(fin);
    pts.push_back(pt);
  }
  for (const auto& pt: pts)
    pt->ShowAll();
  for (auto& pt: pts)
    delete pt;
}

inline void free_io() {
  if (std::cin.fail())
    std::cin.clear();
  clear_buffer();
}

inline void clear_buffer() {
  while (std::cin.get() != '\n')
    continue;
}
