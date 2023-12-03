/* t5.cpp */

#include <iostream>

int main() {
	long long worlds_population;
	long long US_population;

	std::cout << "Enter the world's population: ";
	std::cin >> worlds_population;
	std::cout << "Enter the popultaion of the US: ";
	std::cin >> US_population;

	double percent = (double) US_population / worlds_population * 100;
	std::cout << "The population of the US is " << percent << "\% of the world population." << std::endl;

	return 0;
}
