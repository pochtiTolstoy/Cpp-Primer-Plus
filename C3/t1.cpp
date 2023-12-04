#include <iostream>

int main() {
	const int inches_in_foot = 12;
	int height_inches;
	std::cout << "Enter your height in inches: __\b\b";
	std::cin >> height_inches;

	int height_foot = height_inches / 12;
	int remaining_inches = height_inches % 12;
	std::cout << "Your height is - " << height_foot << 
							 " foots and " << remaining_inches << 
							 " inches." << std::endl;
	return 0;
}
