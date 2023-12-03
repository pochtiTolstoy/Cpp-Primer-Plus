#include <iostream>

double ly_to_au(double);

int main() {
	double light_years;
	std::cout << "Enter the number of light years: ";
	std::cin >> light_years;
	double astronomical_units = ly_to_au(light_years);
	std::cout << light_years << " light years = " << astronomical_units << " astronomical units." << std::endl;

	return 0;
}

double ly_to_au(double light_years) {
	return light_years * 63240; 
}
