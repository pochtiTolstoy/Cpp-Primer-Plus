#include <iostream>

const int SIZE = 10;

int Fill_array(double arr[], int size);
void Show_array(double arr[], int size);
void Reverse_array(double arr[], int size);
void clear_buffer(void);

int main() {
	double arr[SIZE];
	int items = Fill_array(arr, SIZE);
	Show_array(arr, items);
	Reverse_array(arr + 1, items - 2);
	Show_array(arr, items);

	return 0;
}

int Fill_array(double arr[], int size) {
	int items = 0;	
	std::cout << "Enter double value: ";
	while ((std::cin >> arr[items]) && ++items < size)
		std::cout << "Enter next number (q to quit): ";	
	if (std::cin.fail())
		std::cin.clear();
	clear_buffer();
	return items;
}

void clear_buffer(void) {
	while (std::cin.get() != '\n')
		;
}

void Show_array(double arr[], int size) {
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << '\n';
}

void Reverse_array(double arr[], int size) {
	double* begin = arr;
	double* end = arr + size - 1;
	if (begin >= end)
		return;

	double temp;
	for (; begin <= end; ++begin, --end) {
		temp = *begin;
		*begin = *end;
		*end = temp;
	}
}
