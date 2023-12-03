#include <iostream>

void show_time(int, int);

int main() {
	int hours;
	std::cout << "Enter the number of hours: ";
	std::cin >> hours;
	int minutes;
	std::cout << "Enter the number of minutes: ";
	std::cin >> minutes;
	show_time(hours, minutes);

	return 0;
}

void show_time(int hours, int minutes) {
	std::cout << "Time: " << hours << ':' << minutes << std::endl;	
}
