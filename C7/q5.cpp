#include <iostream>

double maxv(const double arr[], int n);

int main() {
	double arr[] = { 2.3, 22.3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	double max = maxv(arr, size);
	std::cout << "Max value in arr: " << max << std::endl;
	return 0;
}

double maxv(const double arr[], int n) {
	if (n < 1) {
		std::cout << "Invalid array size of " << n << std::endl;
		std::cout << "Returning a value of -1\n";
		return -1;
	}
	double max = arr[0];
	for (int i = 1; i < n; ++i)
		max = max < arr[i] ? arr[i] : max;
	return max;
}
