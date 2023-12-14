#include <iostream>

template<typename T>
T mmax(const T& a, const T& b) {
	return a > b ? a : b;
}

int main() {
	int a = 5;
	int b = 10;
	int m = mmax(a, b); // происходит копирование
	std::cout << m << std::endl;

	return 0;
}
