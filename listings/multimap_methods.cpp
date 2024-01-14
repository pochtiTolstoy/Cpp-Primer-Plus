#include <iostream>
#include <string>
#include <map>
#include <algorithm>

typedef int KeyType;
typedef std::pair<const KeyType, std::string> Pair;
typedef std::multimap<KeyType, std::string> MapCode;

int main() {
  MapCode codes;
  codes.insert(Pair(415, "San Francisco"));
  codes.insert(Pair(510, "Oakland"));
  codes.insert(Pair(718, "Brooklyn"));
  codes.insert(Pair(718, "Staten Island"));
  codes.insert(Pair(415, "San Rafael"));
  codes.insert(Pair(510, "Berkeley"));
  std::cout << "Number of citiesd with area code 415: "
    << codes.count(415) << '\n';
  std::cout << "Number of citiesd with area code 718: "
    << codes.count(718) << '\n';
  std::cout << "Number of citiesd with area code 510: "
    << codes.count(510) << '\n';
  std::cout << "Area Code City\n";
  MapCode::iterator it;
  for (it = codes.begin(); it != codes.end(); ++it) {
    std::cout << " " << (*it).first << " " << (*it).second << '\n';
  }
  std::pair<MapCode::iterator, MapCode::iterator> range
    = codes.equal_range(718);
  std::cout << "Citites wit area code 718:\n";
  for (it = range.first; it != range.second; ++it) {
    std::cout << (*it).second << '\n';
  }

  return 0;
}
