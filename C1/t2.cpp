#include <iostream>

int main() {
	int furlongs;
	int value = 220;
	
	std::cout << "Enter a distance in furlongs: ";
	std::cin >> furlongs;

	int yards = furlongs * value;

	std::cout << furlongs << " furlongs is a " << yards << " yards." << std::endl;

	return 0;
}
