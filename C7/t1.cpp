#include <iostream>

double harmonic_mean(double, double);

int main() {
	double a, b;
	std::cout << "Enter two numbers: ";
	while ((std::cin >> a >> b) && a != 0 && b != 0) {
		std::cout << "a = " << a << ", b = " << b 
							<< ", harmonic mean: " << harmonic_mean(a, b) << std::endl;	
		std::cout << "Enter next two numbers or zero if you want to quit: ";
	}
	return 0;
}

double harmonic_mean(double x, double y) {
	return 2.0 * x * y / (x + y);
}
