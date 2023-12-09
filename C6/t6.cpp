#include <iostream>

const int SIZE = 129;
const double Top_tier_donation = 10'000;

struct patrons {
	char fullname[SIZE];
	double donation;
};

int main() {
	int num_patrons;
	std::cout << "Enter number of patrons: ";
	std::cin >> num_patrons;
	std::cin.get();

	patrons* p_club = new patrons[num_patrons];
	for (int i = 0; i < num_patrons; ++i) {
		std::cout << "Patron #" << i + 1 << ":\n";
		std::cout << "Enter full name of patron: ";
		std::cin.getline(p_club[i].fullname, SIZE);

		std::cout << "Enter value of donation: ";
		std::cin >> p_club[i].donation;
		std::cin.get();

		std::cout << std::endl;
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

	return 0;
}
