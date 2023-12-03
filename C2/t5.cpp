#include <iostream>

double cel_to_far(double);

int main() {
	double celsius;
	std::cout << "Please enter a Celsius value: ";
	std::cin >> celsius;

	double fahrenheit = cel_to_far(celsius);
	std::cout << celsius << " degrees Celsius is " << fahrenheit << " degrees Fahrenheit." << std::endl;

	return 0;
}

double cel_to_far(double celsius) {
	return 1.8 * celsius + 32.0;
}
