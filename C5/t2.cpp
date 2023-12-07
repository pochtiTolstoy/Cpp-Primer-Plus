#include <iostream>
#include <array>

const int ArSize = 101;

int main() {
	//long long factorials[ArSize];
	std::array<long double, ArSize> factorials = {0};
	factorials[1] = factorials[0] = 1L;
	/*
	* The type of a floating literal is double unless explicitly
	* specified by a suffix. The suffixes f and F specify float,
	* the suffixes l and L specify long double.
	*/

	for (int i = 2; i < ArSize; ++i)
		factorials[i] = i * factorials[i - 1];
	
	for (int i = 0; i < ArSize; ++i)
		std::cout << i << "! = " << factorials[i] << std::endl;

	return 0;
}
