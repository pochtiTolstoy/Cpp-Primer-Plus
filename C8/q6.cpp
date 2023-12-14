#include <iostream>

double mass(double dens);
double mass(double dens, double vol);

void repeat(int n, const char*);
void repeat(const char*);

int avg(int, int);
double avg(double, double);

int main() {

	return 0;
}

double mass(double dens) {
	return dens * 1.0;
}

double mass(double dens, double vol) {
	return dens * vol;
}

void repeat(int n, const char* str) {
	for (int i = 0; i < n; ++i)
		std::cout << str;
}
void repeat(const char* str) {
	for (int i = 0; i < 5; ++i)
		std::cout << str;
}

int avg(int a, int b) {
	return (a + b) / 2;
}
double avg(double a, double b) {
	return (a + b) / 2;
}
