#include <iostream>

struct box {
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

template<typename T>
T mmax(const T& a, const T& b);

template<> box mmax<box>(const box&, const box&);

int main() {
	double a = 5.6;
	double b = 6.6;
	std::cout << mmax(a, b) << std::endl;

	box b1 = { "A", 0, 0, 0, 1.2 };
	box b2 = { "B", 1, 1, 1, 0 };
	std::cout << mmax(b1, b2).volume << std::endl;
	return 0;
}


template<typename T>
T mmax(const T& a, const T& b) {
	return a > b ? a : b;
}

template<> box mmax<box>(const box& b1, const box& b2) {
	return b1.volume > b2.volume ? b1 : b2;
}
