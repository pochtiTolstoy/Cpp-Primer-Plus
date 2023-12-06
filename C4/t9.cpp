#include <iostream>

const int Size = 65;

struct CandyBar {
	char name[Size];
	double weight;
	int kalories;
};

void print_candy(const struct CandyBar bar[]);

int main() {
	int Size = 3;
	CandyBar* pbar = new CandyBar[Size];
	pbar[0] = { "Snikers", 20.1, 300 };
	pbar[1] = { "Mars",    10.2, 340 };
	pbar[2] = { "Twix",    9.8,  270 };

	print_candy(pbar);       // &pbar[0] = &(*(pbar + 0) = &(*pbar) = pbar	
	print_candy(pbar + 1);   //&pbar[1] = &(*(pbar + 1)) = pbar + 1	
	print_candy(pbar + 2);	

	delete[] pbar;
	return 0;
}

void print_candy(const struct CandyBar* pbar) {
	std::cout << "Candy! Name: " << pbar->name 
						<< ", weight "     << pbar->weight 
						<< ", kalories "   << pbar->kalories 
						<< std::endl;
}
