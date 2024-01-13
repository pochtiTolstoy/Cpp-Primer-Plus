#include <iostream>
#include <string>
#include <memory>

int main() {
  std::shared_ptr<std::string> films[5] = {
    std::shared_ptr<std::string> (new std::string("A~~")),
    std::shared_ptr<std::string> (new std::string("B~~")),
    std::shared_ptr<std::string> (new std::string("C~~")),
    std::shared_ptr<std::string> (new std::string("D~~")),
    std::shared_ptr<std::string> (new std::string("E~~"))
  };
  std::shared_ptr<std::string> pwin;
  pwin = films[2]; // C~~ Увеличиваем счётчик ссылок на 2
  std::cout << "Info:\n";
  for (int i = 0; i < 5; ++i)
    std::cout << *films[i] << '\n';
  std::cout << "The winner is " << *pwin << "!\n";
  // Снимается со стека pwin, уменьшается счётчик ссылок до 1
  // Снимаем массив со стека, при удалении указателей, вызывается деструктор,
  // счётчик ссылок каждого элемента уменьшается до 0.
  // Значит вызывается delete p и память в куче освобождается.
  return 0;
}
