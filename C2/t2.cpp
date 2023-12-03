#include <iostream>

int main() {
	int yards_in_furlong = 220;
	int furlongs;

	std::cout << "Enter a distance in furlongs: ";
	std::cin >> furlongs;

	int yards = furlongs * yards_in_furlong;
	std::cout << furlongs << " furlongs is " << yards << " yards." << std::endl;

	return 0;
}
