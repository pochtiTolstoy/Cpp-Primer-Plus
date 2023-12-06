#include <iostream>

const int Size = 65;

struct CandyBar {
	char name[Size];
	double weight;
	int kalories;
};

void print_candy(const struct CandyBar bar[]);

int main() {
	CandyBar bar[3] = {
		{ "Snikers", 20.1, 300 },
		{ "Mars",    10.2, 340 },
		{ "Twix",    9.8,  270 }
	};
	print_candy(&bar[0]);	
	print_candy(&bar[1]);	
	print_candy(&bar[2]);	

	return 0;
}

void print_candy(const struct CandyBar* pbar) {
	std::cout << "Candy! Name: " << pbar->name <<
							 ", weight "     << pbar->weight <<
							 ", kalories "   << pbar->kalories << std::endl;
}
