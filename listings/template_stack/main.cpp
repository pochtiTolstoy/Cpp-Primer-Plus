#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stack.h"

const int Num = 10;

int main() {
  std::srand(std::time(0));
  std::cout << "Please enter stack size: ";
  int stacksize;
  std::cin >> stacksize;
  Stack<const char*> st(stacksize); // T = const char*
  //T* items_ = new T[n]; В каждой ячейке такого динамического массива,
  // будет лежать указатель на строку в стиле C
  // Массив на стеке в памяти, автоматическая память
  const char* in[Num] = {
    " 1: Hank Gilgamesh",  " 2: Kiki Ishtar",
    " 3: Betty Rocker",    " 4: Ian Flagranti",
    " 5: Wolfgang Kibble", " 6: Protia Koop",
    " 7: Joy Almondo",     " 8: Xaverie Paprika",
    " 9: Juan Moore",      "10: Misha Mache"
  }; 
  // Эти строки нельзя заменить, они в статической памяти, мы храним лишь указатели
  // на них
  const char* out[Num]; // out box
  int processed = 0;
  int nextin = 0;
  // Пока не обработаем все Num элементов
  while (processed < Num) {
    if (st.isempty())
      st.push(in[nextin++]);
    else if (st.isfull())
      st.pop(out[processed++]);
    else if (std::rand() % 2 && nextin < Num)
      st.push(in[nextin++]);
    else
      st.pop(out[processed++]);
  }
  for (int i = 0; i < Num; ++i)
    std::cout << out[i] << '\n';
  std::cout << "Bye!\n";
  // По идеи в конце будет по три указателя, которые указывают на одну статическую
  // память.
  return 0;
}
