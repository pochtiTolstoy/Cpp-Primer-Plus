#include <iostream>

const int size = 65;

struct CandyBar {
	char name[size];
	double weight;
	int kalories;
};

int main() {
	CandyBar snack = {
		"Mocha Munch",
		2.3,
		350
	};

	std::cout << "Candy! Name: " << snack.name << 
							 ", weight: " << snack.weight << 
							 ", kalories: " << snack.kalories << std::endl;

	return 0;
}
