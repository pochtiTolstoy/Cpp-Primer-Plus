#include <iostream>

int main() {
	int rows;
	std::cout << "Enter number of rows: ";
	std::cin >> rows;

	int dots, stars;
	for (dots = rows - 1, stars = 1; stars <= rows; --dots, ++stars) {
		for (int elem = 0; elem < dots; ++elem)
			std::cout << '.';
		for (int elem = 0; elem < stars; ++elem)
			std::cout << '*';
		std::cout << '\n';
	}
	return 0;
}
