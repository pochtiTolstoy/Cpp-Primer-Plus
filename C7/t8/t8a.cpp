#include <iostream>
//#include <array>

const int Seasons = 4;
/*
const std::array<std::string, Seasons> Snames = 
	{"Spring", "Summer", "Fall", "Winter"};
*/
const char* Snames[Seasons] = { "Spring", "Summer", "Fall", "Winter" };

/*
void fill(std::array<double, Seasons>* pa);
void show(std::array<double, Seasons> da);
*/
void fill(double arr[]);
void show(const double arr[]);

int main() {
	//std::array<double, Seasons> expenses;
	double expenses[Seasons];
	fill(expenses);
	show(expenses);
	return 0;
}

void fill(double arr[]) {
	for (int i = 0; i < Seasons; ++i) {
		std::cout << "Enter " << Snames[i] << " expenses: ";
		std::cin >> arr[i];
	}
}

void show(const double arr[]) {
	double total = 0.0;
	std::cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; ++i) {
		std::cout << Snames[i] << ": $" << arr[i] << std::endl;
		total += arr[i];
	}
	std::cout << "Total Expenses: $" << total << std::endl;
}
