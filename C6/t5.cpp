#include <iostream>

const float Percent_tier1 = 0.00f;
const float Percent_tier2 = 0.10f;
const float Percent_tier3 = 0.15f;
const float Percent_tier4 = 0.20f;
const double Tier1 = 5000;
const double Tier2 = 10000;
const double Tier3 = 20000;
const double Tier4 = 35000;

void clear_buffer(void);
double calculate_taxes(double);

int main() {
	double income = 0;
	double taxes = 0;
	std::cout << "Enter your income (q for quit): ";
	while (std::cin >> income && income >= 0) {
		taxes = calculate_taxes(income);
		std::cout << "Income: " << income << ", taxes: " << taxes << std::endl;
		std::cout << "Enter next value: ";
	}
	if (std::cin.fail())
		std::cin.clear();
	clear_buffer();

	return 0;
}

void clear_buffer(void) {
	while (std::cin.get() != '\n')
		continue;
}

double calculate_taxes(double income) {
	double taxes = 0;
	if (income > Tier4)                 					// if greater than 35000
		taxes += Tier1 * Percent_tier1 +  					// Add 5000 * 0.0f
						 Tier2 * Percent_tier2 +  					// Add 10000 * 0.1f
						 Tier3 * Percent_tier3 +  					// Add 20000 * 0.2f
						 (income - Tier4) * Percent_tier4;  // Add percent of remainder that greater 35000

	else if (income > Tier1 + Tier2)    					// if less or eq than 35000, but greater than 15000
		taxes += Tier1 * Percent_tier1 +						// Add 5000 * 0.0f
						 Tier2 * Percent_tier2 +						// Add 10000 * 0.1f
						 (income - Tier1 - Tier2) * Percent_tier3; // Add percent of remainder

	else if (income > Tier1)            					// less or eq than 15000, but greater than 5000
		taxes += Tier1 * Percent_tier1 +						// Add 5000 * 0.0f
					   (income - Tier1) * Percent_tier2;  // Add percent of reaminder

	else                               						// less or eq than 5000
		taxes += income * Percent_tier1;

	return taxes;
}
