#include <iostream>

int main() {
	int kilometers;
	int petrol;

	std::cout << "Enter a distance in kilometers: ";
	std::cin >> kilometers;
	std::cout << "Enter a petrol in liters: ";
	std::cin >> petrol;

	double liters_per_kilometers = (double) petrol * 100 / kilometers;
	std::cout << "Liters per 100 kilometers: " << liters_per_kilometers << std::endl;

	return 0;
}
