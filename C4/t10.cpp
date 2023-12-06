#include <iostream>
#include <array>

int main() {
	const int Size = 3;
	std::array<float, Size> data;
	std::cout << "Enter result of first run in 40 meters: ";
	std::cin >> data[0];
	std::cout << "Enter result of second run in 40 meters: ";
	std::cin >> data[1];
	std::cout << "Enter result of third run in 40 meters: ";
	std::cin >> data[2];
	std::cin.get(); //read last '\n'

	std::cout << "Data from three runs:\n";
	std::cout << "First run:  " << data[0] << std::endl;
	std::cout << "Second run: " << data[1] << std::endl;
	std::cout << "Third run:  " << data[2] << std::endl;

	double average = (data[0] + data[1] + data[2]) / Size;
	std::cout << "Average result: " << average << std::endl;

	return 0;
}
