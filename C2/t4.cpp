#include <iostream>

int main() {
	int months_in_year = 12;
	int user_years;
	std::cout << "Enter you age: ";
	std::cin >> user_years;

	int user_months = user_years * months_in_year;
	std::cout << "Your age in months is " << user_months << std::endl;

	return 0;
}
