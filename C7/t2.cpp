#include <iostream>

const int SIZE = 10;

void get_data(int arr[], int n, int*);
void show_data(const int arr[], int n);
void show_avg(double avg);
double calc_average(const int arr[], int n);
void clear_buffer(void);
void fail_read(void);

int main() {
	int arr[SIZE];
	int items = 0;
	get_data(arr, SIZE, &items); // after work only with items and not SIZE
	show_data(arr, items);
	show_avg(calc_average(arr, items));
	return 0;
}

void get_data(int arr[], int n, int* p_items) {
	std::cout << "Enter 10 result of game (or q to quit):\n";
	for (int i = 0; i < n; ++i) {
		std::cout << '#' << i + 1 << ": ";
		if (!(std::cin >> arr[i])) {
			fail_read();
			return;
		}
		++*p_items;
	}
	// we read all SIZE values, but we have '\n' in our buffer. 
	clear_buffer();
}

void clear_buffer(void) {
	while (std::cin.get() != '\n')
		continue;
}

void fail_read(void) {
	std::cin.clear();
	clear_buffer();
}

void show_data(const int arr[], int n) {
	if (n <= 0) {
		std::cout << "You have entered 0 values.\n";
		return;
	}
	std::cout << "Data: ";
	for (int i = 0; i < n; ++i)
		std::cout << arr[i] << ' ';
	std::cout << '\n';
}

double calc_average(const int arr[], int n) {
	if (n <= 0) {
		std::cout << "Can't calculate average value. Will return 0.\n";
		return 0;
	}
	double avg = 0.0;
	for (int i = 0; i < n; ++i)
		avg += arr[i];
	return avg / n;
}

void show_avg(double avg) {
	std::cout << "Average value: " << avg << std::endl;
}
