#include <iostream>
#include <cstdlib>
#include <fstream>

const int SIZE = 129;
const double Top_tier_donation = 10'000;

struct patrons {
	char fullname[SIZE];
	double donation;
};

int main() {
	char filename[SIZE];
	std::cout << "Enter a file name: ";
	std::cin >> filename; // reads one word

	std::ifstream in;
	in.open(filename);
	if (!in.is_open()) {
		std::cout << "Error. Can't open file: " << filename << std::endl;	
		exit(EXIT_FAILURE);
	}
	int num_patrons;
	in >> num_patrons;
	in.get(); // to read '\n'

	patrons* p_club = new patrons[num_patrons];
	for (int i = 0; i < num_patrons; ++i) {
		in.getline(p_club[i].fullname, SIZE);
		in >> p_club[i].donation;
		in.get();
	}

	std::cout << "Grand Patrons\n";
	int cnt = 0;
	for (int i = 0; i < num_patrons; ++i) {
		if (p_club[i].donation >= Top_tier_donation) {
			std::cout << p_club[i].fullname << ": " 
								<< p_club[i].donation << std::endl;
			++cnt;
		}
	}
	if (cnt == 0)
		std::cout << "none\n";
	std::cout << std::endl;

	std::cout << "Patrons\n";
	cnt = 0;
	for (int i = 0; i < num_patrons; ++i) {
		if (p_club[i].donation < Top_tier_donation) {
			std::cout << p_club[i].fullname << ": " 
								<< p_club[i].donation << std::endl;
			++cnt;
		}
	}
	if (cnt == 0)
		std::cout << "none\n";
	std::cout << std::endl;

	delete[] p_club;
	in.close();

	return 0;
}
