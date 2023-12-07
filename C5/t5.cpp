#include <iostream>

const int Months_in_year = 12;
const int Good_sales_for_year = 500;

int main() {
	const char* Months[Months_in_year] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	int sales_per_month[Months_in_year] = {0};

	std::cout << "Enter how much book did you sell in last year.\n";
	for (int month = 0; month < Months_in_year; ++month) {
		std::cout << "Month: " << Months[month] << ", enter a number: ";
		std::cin >> sales_per_month[month];
	}
	std::cin.get();

	int sales_in_year = 0;
	for (int month = 0; month < Months_in_year; ++month)
		sales_in_year += sales_per_month[month];

	std::cout << "You sold " << sales_in_year << " books in the last year";
	if (sales_in_year > Good_sales_for_year)
		std::cout << "! Good job! You are awesome!\n";
	else
		std::cout << ". It is nice result, but you should work harder!\n";

	return 0;
}
