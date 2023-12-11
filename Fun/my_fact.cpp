#include <iostream>

const int SIZE = 5000; // 5000 digits number

int* factorial(int num);
void calc_fact(int arr[], int num);
void display_large_number(int*);

int main() {
	int num;
	std::cout << "Enter the number: ";
	std::cin >> num;
	
	int* p_large_number = factorial(num); // we can play with our number in function main after calculating
	std::cout << num << "! = ";
	display_large_number(p_large_number);
	std::cout << '\n';

	delete[] p_large_number;
	return 0;
}

int* factorial(int num) {
	int* arr = new int[SIZE]; // but better to do like vector with realloc	
	for (int i = 0; i < SIZE; ++i)
		arr[i] = 0;

	if (num < 0) {
		std::cout << "Num is less than zero!\n";
		std::cout << "Return 0.\n";
		return arr;
	} 

	arr[SIZE - 1] = 1;
	calc_fact(arr, num);
	return arr;
}

void calc_fact(int arr[], int num) {
	if (num == 0) return;
	int carry = 0;
	// every ceil of array is digit in our large number
	for (int i = SIZE - 1; i >= 0; --i) {
		arr[i] = (arr[i] * num) + carry;
		carry = arr[i] / 10;
		arr[i] %= 10;
	}

	calc_fact(arr, num - 1);
}

void display_large_number(int* p_large_number) {
	int flag = 0;
	for (int i = 0; i < SIZE; ++i) {
		if (!flag && p_large_number[i])
			flag = 1;
		if (flag)
			std::cout << p_large_number[i];
	}
}
