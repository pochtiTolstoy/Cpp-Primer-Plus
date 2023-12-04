#include <iostream>

int main() {
	const int Time_factor = 60;
	const int Hours_in_day = 24;
	const int Sec_in_min = Time_factor;
	const int Sec_in_hour = Sec_in_min * Time_factor;
	const int Sec_in_day = Sec_in_hour * Hours_in_day; 

	long long seconds;
	std::cout << "Enter the number of seconds: ";
	std::cin >> seconds;

	int remaining_seconds;
	int days = seconds / Sec_in_day;
	remaining_seconds = seconds % Sec_in_day;
	int hours = remaining_seconds / Sec_in_hour;
	remaining_seconds %= Sec_in_hour;
	int minutes = remaining_seconds / Sec_in_min;
	remaining_seconds %= Sec_in_min;

	std::cout << seconds << " seconds = " << days << " days, " << 
							 hours << " hours, " << minutes << " minutes, " <<
							 remaining_seconds << " seconds\n";

	return 0;
}
