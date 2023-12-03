#include <iostream>

int main() {
	int user_age;
	int months_in_year = 12;
	int user_months;

	std::cout << "Please, enter your age: ";
	std::cin >> user_age;

	user_months = user_age * months_in_year;
	std::cout << "Your age in months is " << user_months << std::endl;

	return 0;
}
