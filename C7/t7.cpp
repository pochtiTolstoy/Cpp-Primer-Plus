#include <iostream>

const int Max = 5;

double* fill_array(double* begin, const double* const end);
void show_array(const double* begin, const double* const end);
void revalue(double r, double* begin, const double* const end);
void clear_buffer(void);

int main() {
	double properties[Max];
	double* begin = properties;
	double* end = fill_array(begin, begin + Max);
	show_array(begin, end);
	if (begin != end) {
		std::cout << "Enter revaluation factor: ";
		double factor;
		while (!(std::cin >> factor)) {
			std::cin.clear();
			clear_buffer();
			std::cout << "Bad input; Please enter a number: ";
		}
		revalue(factor, begin, end);
		show_array(begin, end);
	}
	std::cout << "End.\n";
	return 0;
}

double* fill_array(double* begin, const double* const end) {
	double temp;
	int id = 1;
	while (begin < end) {
		std::cout << "Enter value #" << id++ << ": ";
		if (!(std::cin >> temp)) {
			std::cout << "Bad input; input process terminated.\n";
			break;
		} else if (temp < 0)
			break;
		*begin++ = temp;
	}
	if (std::cin.fail())
		std::cin.clear();
	clear_buffer();
	return begin;
}

void revalue(double r, double* begin, const double* const end) {
	while (begin < end)
		*begin++ *= r;
}

void show_array(const double* begin, const double* const end) {
	int id = 1;
	while (begin < end)
		std::cout << "Property #" << id++ << ": $"
							<< *begin++ << std::endl;
}

void clear_buffer(void) {
	while (std::cin.get() != '\n')
		continue;
}
