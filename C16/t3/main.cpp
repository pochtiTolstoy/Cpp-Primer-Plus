#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <fstream>

std::string& ToLower(std::string& st);
char toLower(char ch);
bool is_game_word(const std::string& st);

int main() {
  std::ifstream in;
  in.open("data.txt");
  if (!in.is_open()) {
    std::cout << "File is not open.\n";
    exit(EXIT_FAILURE);
  }
  std::vector<std::string> data;
  std::string st;
  std::cout << "Loading words from the database...\n";
  while (in >> st) {
    if (is_game_word(st)) data.push_back(ToLower(st));
  }
  int NUM = data.size();
  if (NUM == 0) {
    std::cout << "The download failed. Loaded: 0 words.\n"
      << "Try to update the database with words.\n";
  } else {
    std::cout << "Download was successful. Loaded: " << data.size() << " words.\n";
  }
  in.close();
  std::srand(std::time(0));
  char play;
  std::cout << "Will you play a word game? <y/n>: ";
  std::cin >> play;
  play = tolower(play);
  while (play == 'y') {
    std::string target = data[std::rand() & NUM];
    int length = target.length();
    std::string attempt(length, '-');
    std::string badchars;
    int guesses = 6;
    std::cout << "Guess my secret word. It has " << length
      << " letters, and you guess\n"
      << "one letter at a time. You get " << guesses
      << " wrong guesses.\n";
    std::cout << "Your word: " << attempt << std::endl;
    while (guesses > 0 && attempt != target) {
      char letter;
      std::cout << "Guesses a letter: ";
      std::cin >> letter;
      if (badchars.find(letter) != std::string::npos
        || attempt.find(letter) != std::string::npos) {
        std::cout << "You already guessed that. Try again.\n";
        continue;
      }
      int loc = target.find(letter);
      if (loc == std::string::npos) {
        std::cout << "Oh, bad guess!\n";
        --guesses;
        badchars += letter;
      } else {
        std::cout << "Good guess!\n";
        attempt[loc] = letter;
        loc = target.find(letter, loc + 1);
        while (loc != std::string::npos) {
          attempt[loc] = letter;
          loc = target.find(letter, loc + 1);
        }
      }
      std::cout << "Your word: " << attempt << '\n';
      if (attempt != target) {
        if (badchars.length() > 0)
          std::cout << "Bad choices: " << badchars << '\n';
        std::cout << guesses << " bad guesses left\n";
      }
    }
    if (guesses > 0)
      std::cout << "That's right!\n";
    else
      std::cout << "Sorry, the word is " << target  << ".\n";
    std::cout << "Will you play another? <y/n> ";
    std::cin >> play;
    play = tolower(play);
  }
  std::cout << "Bye!\n";
  return 0;
}

std::string& ToLower(std::string& st) {
  std::transform(st.begin(), st.end(), st.begin(), toLower);
  return st;
}

char toLower(char ch) {
  return tolower(ch);
}

bool is_game_word(const std::string& st) {
  auto iter = st.begin();
  while (iter != st.end()) {
    if (!isalpha(*iter++)) return false;
  }
  return true;
}
