#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>

char toLower(char ch) { return tolower(ch); }
std::string& ToLower(std::string& st);
void display(const std::string& s);

int main() {
  std::vector<std::string> words;
  std::cout << "Enter words (enter quit to quit):\n";
  std::string input;
  while (std::cin >> input && input != "quit")
    words.push_back(input);
  std::cout << "You entered the following words:\n";
  for_each(words.begin(), words.end(), display);
  std::cout << '\n';

  std::set<std::string> wordset;
  std::transform(
    words.begin(), words.end(),
    std::insert_iterator<std::set<std::string>>(wordset, wordset.begin()),
    ToLower
  );
  std::cout << "\nAlphabetic list of words:\n";
  for_each(wordset.begin(), wordset.end(), display);
  std::cout << '\n';

  std::cout << "Source vector after creating wordset and transform\n";
  for_each(words.begin(), words.end(), display);
  std::cout << '\n';

  std::map<std::string, int> wordmap; 
  std::set<std::string>::iterator si;
  for (si = wordset.begin(); si != wordset.end(); ++si) {
    int cnt = count(words.begin(), words.end(), *si);
    wordmap[*si] = cnt;
    std::cout << "count freq of: " << *si << " is " << cnt << '\n';
  }
  std::cout << "\nWord frequency:\n";
  for (si = wordset.begin(); si != wordset.end(); ++si)
    std::cout << *si << ": " << wordmap[*si] << '\n';

  return 0;
}

std::string& ToLower(std::string& st) {
  std::transform(st.begin(), st.end(), st.begin(), toLower);
  return st;
}

void display(const std::string& s) {
  std::cout << s << ' ';
}
