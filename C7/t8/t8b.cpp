#include <iostream>
//#include <array>

const int Seasons = 4;
/*
const std::array<std::string, Seasons> Snames = 
	{"Spring", "Summer", "Fall", "Winter"};
*/
const char* Snames[Seasons] = { "Spring", "Summer", "Fall", "Winter" };
struct data {
	double expenses[Seasons];
};

/*
void fill(std::array<double, Seasons>* pa);
void show(std::array<double, Seasons> da);
*/
void fill(data* pd);
void show(const data* pd);

int main() {
	//std::array<double, Seasons> expenses;
	//double expenses[Seasons];
	data d;
	fill(&d);
	show(&d);
	return 0;
}

void fill(data* pd) {
	for (int i = 0; i < Seasons; ++i) {
		std::cout << "Enter " << Snames[i] << " expenses: ";
		std::cin >> pd->expenses[i];
	}
}

void show(const data* pd) {
	double total = 0.0;
	std::cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; ++i) {
		std::cout << Snames[i] << ": $" << pd->expenses[i] << std::endl;
		total += pd->expenses[i];
	}
	std::cout << "Total Expenses: $" << total << std::endl;
}
