#include <iostream>

const int SIZE = 10;

int main() {
	double data[SIZE];
	int i = 0;
	while (i < SIZE && std::cin >> data[i])
		++i;
	
	if (std::cin.fail())
		std::cout << "Find non-numerical data.\n";
	if (i == 0) {
		std::cout << "No values.\n";
		exit(0);
	}

	float avg = 0;
	for (int j = 0; j < i; ++j)
		avg += data[j];	
	avg /= i;
	std::cout << "Average value: " << avg << std::endl;

	int cnt = 0;
	for (int j = 0; j < i; ++j)
		if (data[j] > avg)
			++cnt;
	std::cout << cnt << " numbers is greater than avg value.\n";	

	return 0;
}
