#include <iostream>

int main() {
	const int inches_in_foot = 12;
	const double inch_to_meters = 0.0254;
	const double pounds_in_kilo = 2.2;

	int foots, inches;
	std::cout << "Enter your height in foot and inches: ";
	std::cin >> foots >> inches;

	int pounds;
	std::cout << "Enter your weight in pounds: ";
	std::cin >> pounds;

	int height_in_inches = foots * inches_in_foot + inches;
	double height_in_meters = height_in_inches * inch_to_meters;
	double weight_in_kilo = pounds / pounds_in_kilo;
	double BMI = weight_in_kilo / (height_in_meters * height_in_meters);
	std::cout << "Your BMI index is - " << BMI << std::endl;

	return 0;
}
