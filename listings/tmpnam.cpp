#include <cstdio>
#include <iostream>

int main() {
  std::cout << "This system can generate up to " << TMP_MAX
    << " temporary names of up to " << L_tmpnam
    << " characters.\n";
  char pszName[L_tmpnam] = { '\0' };
  std::cout << "Here are ten names:\n";
  for (int i = 0; i < 10; ++i) {
    tmpnam(pszName);
    std::cout << pszName << std::endl;
  }
  return 0;
}
