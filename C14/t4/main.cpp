#include <cstring>
#include <iostream>
#include "person.h"
#include "pokerplayer.h"
#include "gunslinger.h"
#include "card.h"
#include "baddude.h"

const int SIZE = 5;

int main() {
  using std::cin;
  using std::cout;
  using std::endl;
  using std::strchr;
  Person* ptr[SIZE];
  int items = 0;
  for (int i = 0; i < SIZE; ++i) {
    char choice;
    cout << "Enter the person category:\n"
         << "p: Person\tg: Gunslinger\t"
         << "o: PokerPlayer\tb: BadDude\t"
         << "q: quit\n";
    cin >> choice;
    while (strchr("pgobq", choice) == NULL) {
      cout << "Please enter a p, g, o, b, q: ";
      cin >> choice;
    }
    if (choice == 'q') {
      break;
    } else {
      switch(choice) {
      case 'p': ptr[i] = new Person; break;
      case 'g': ptr[i] = new Gunslinger; break;
      case 'o': ptr[i] = new Pokerplayer; break;
      case 'b': ptr[i] = new Baddude; break;
      }
      cin.get();
      ptr[i]->Set();
      ++items;
    }
  }
  cout << "\nHere are results:\n";
  for (int i = 0; i < items; ++i) {
    cout << endl;
    ptr[i]->Show();
  }
  for (int i = 0; i < items; ++i) {
    delete ptr[i];
  }
  cout << "Bye.\n";
  return 0;
}
