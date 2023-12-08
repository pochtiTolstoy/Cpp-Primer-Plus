#include <iostream>
#include <cctype>

int main() {
	char ch;
	while (std::cin.get(ch) && ch != '@') {
		if (!isdigit(ch)) {
			ch = islower(ch) ? toupper(ch) : tolower(ch);
			std::cout << ch;
		}
	}
	return 0;
}
