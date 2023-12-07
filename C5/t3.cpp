#include <iostream>

enum { QUIT };

int main() {
	int num;
	std::cout << "Enter a number! Let's go (or type 0 to quit the programm): ";
	std::cin >> num;

	int sum = 0;
	while (num != QUIT) {
		sum += num;
		std::cout << "Current sum: " << sum << std::endl;
		std::cout << "Enter new num: ";
		std::cin >> num;
	}
	std::cin.get();

	std::cout << std::endl << "Final sum is " << sum << std::endl;

	return 0;
}
