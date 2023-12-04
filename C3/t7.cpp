#include <iostream>

int main() {
	const double liters_in_gallon = 3.875;
	const double miles_in_hundred_kilo = 62.14;
	double fuel_per_hundred_kilometers;
	std::cout << "Enter your fuel per hundred kilometers: ";
	std::cin >> fuel_per_hundred_kilometers;

	double gallons = fuel_per_hundred_kilometers / liters_in_gallon;
	std::cout << gallons << " gallons" << std::endl;

	int miles_per_gallon = miles_in_hundred_kilo / gallons;
	std::cout << fuel_per_hundred_kilometers << " liters in 100 kilometers is equal to " << 
							 miles_per_gallon << " miles per gallon\n";

	return 0;
}
