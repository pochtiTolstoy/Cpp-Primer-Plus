#include <iostream>

int main() {
	long long worlds_population;
	std::cout << "Enter the world's population: ";
	std::cin >> worlds_population;

	long long US_population;
	std::cout << "Enter the population of the US: ";
	std::cin >> US_population;

	double percent = US_population * 100.0 / worlds_population;
	std::cout << "The population of the US is " << percent << " \% of the world population.\n";

	return 0;
}
