#include <iostream>

int main() {
	for (int i = 1; i <= 64; i <<= 1)
		std::cout << i << ' ';
	std::cout << '\n';
	return 0;
}
