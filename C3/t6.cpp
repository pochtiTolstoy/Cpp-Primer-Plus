#include <iostream>

int main() {
	double kilometers;
	std::cout << "Enter distance in kilometers: ";
	std::cin >> kilometers;

	double fuel_in_liters;
	std::cout << "Enter fuel in liters: ";
	std::cin >> fuel_in_liters;

	double fuel_per_hundred_kilometers = fuel_in_liters * 100 / kilometers;
	std::cout << "Your spent fuel per hundred kilometers is " << fuel_per_hundred_kilometers << std::endl;

	return 0;
}
