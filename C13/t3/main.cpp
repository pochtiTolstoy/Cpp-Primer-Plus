#include <iostream>
#include <cstdlib>
#include "dma.h"

enum { BDMA = 1, LDMA, HDMA, QUIT };

void free_io(void);
void clear_buffer(void);
void menu(void);
void get_button(int&);
baseDMA build_BDMA(void);
void get_bdma(abcDMA**);
void get_ldma(abcDMA**);
void get_hdma(abcDMA**);

int main() {
  int n;
  std::cout << "Enter number of elements: ";
  while (!(std::cin >> n) || n <= 0) {
    clear_buffer();
    std::cout << "Please enter integer value: ";
  }
  clear_buffer();
  abcDMA** data = new abcDMA*[n];
  int choice = 0;
  int items = 0;
  while (items < n && choice != QUIT) {
    menu(); 
    get_button(choice);
    switch (choice) {
      case BDMA: get_bdma(&data[items]);
        break;
      case LDMA: get_ldma(&data[items]);
        break;
      case HDMA: get_hdma(&data[items]);
        break;
      case QUIT: --items; std::cout << "Quiting menu.\n"; 
        break;
      default:
        std::cout << "Error choice.\n";
        exit(EXIT_FAILURE);
    }
    ++items;
  }
  if (items == 0) std::cout << "There are no elements in data.\n";
  std::cout << '\n';
  for (int i = 0; i < items; ++i) {
    std::cout << i + 1 << ": ";
    data[i]->View();
  }
  baseDMA shirt("P", 7);
  lacksDMA balloon("red", "bimpo", 4);
  hasDMA map("Mer", "BUF", 6);

  std::cout << "Displaying baseDMA:\n";
  std::cout << shirt << '\n';

  std::cout << "Displaying lacksDMA:\n";
  std::cout << balloon << '\n';

  std::cout << "Displaying hasDMA:\n";
  std::cout << map << '\n';

  lacksDMA balloon2(balloon);
  std::cout << "Result of lacksDMA copy constructor:\n";
  std::cout << balloon2 << std::endl;

  hasDMA map2;
  map2 = map;
  std::cout << "Result of hasDMA assignment operator:\n";
  std::cout << map2 << std::endl;

  std::cout << "Bye!\n";

  for (int i = 0; i < items; ++i)
    delete data[i];
  delete[] data;
  return 0;
}

void free_io(void) {
  if (std::cin.fail())
    std::cin.clear();
  clear_buffer();
}
void clear_buffer(void) {
  while (std::cin.get() != '\n')
    continue;
}

void menu(void) {
  std::cout << "Enter type of element:\n"
    << "1. baseDMA    2. lacksDMA\n"
    << "3. hasDMA     4. Quit\n";
}

void get_button(int& num) {
  std::cout << "--enter: ";
  while (!(std::cin >> num) || num < BDMA || num > QUIT) {
    free_io();
    std::cout << "Enter an integer value (1-4): ";
  }
  free_io();
}


baseDMA build_BDMA(void) {
  const int SIZE = 65;
  char label[SIZE];
  int rating;
  std::cout << "Enter label name: ";
  if (!std::cin.getline(label, SIZE)) free_io();
  std::cout << "Enter ratring: ";
  while (!(std::cin >> rating)) {
    free_io();
    std::cout << "Please, enter an integer value: ";
  }
  free_io();
  return baseDMA(label, rating);
}

void get_bdma(abcDMA** pp_obj) {
  *pp_obj = new baseDMA(build_BDMA());
}

void get_ldma(abcDMA** pp_obj) {
  static char color[40];
  std::cout << "Enter color: ";
  if (!std::cin.getline(color, 40)) free_io();
  *pp_obj = new lacksDMA(color, build_BDMA());
}

void get_hdma(abcDMA** pp_obj) {
  static char style[256];
  std::cout << "Enter style: ";
  if (!std::cin.getline(style, 256)) free_io();
  *pp_obj = new hasDMA(style, build_BDMA());
}
