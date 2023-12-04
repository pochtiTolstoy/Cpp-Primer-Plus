#include <iostream>

int main() {
	const double Factor = 60.0;
	
	std::cout << "Enter a latitude in degrees, minutes, and seconds:" << std::endl;

	double degrees;
	std::cout << "First, enter the degrees: ";
	std::cin >> degrees;

	double minutes;
	std::cout << "Next, enter the minutes of arc: ";
	std::cin >> minutes;

	double seconds;
	std::cout << "Finally, enter the seconds of arc: ";
	std::cin >> seconds;


	double arc_degrees = degrees + minutes / Factor + seconds / (Factor * Factor);
	std::cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = ";
	std::cout << arc_degrees << " degrees\n"; 

	return 0;
}
