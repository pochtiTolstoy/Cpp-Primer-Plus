#include <iostream>

unsigned long long factorial(unsigned long long num);
void clear_buffer(void);

int main() {
	std::cout << "Enter number to get its factorial (or q to quit): ";
	int num;
	while ((std::cin >> num) && num >= 0) {
		std::cout << num << "! = " << factorial(num) << std::endl;	
		std::cout << "Enter next number: ";
	}
	if (std::cin.fail())
		std::cin.clear();
	clear_buffer();

	return 0;
}

unsigned long long factorial(unsigned long long num) {
	if (num <= 1)
		return 1;
	return num * factorial(num - 1);
}

void clear_buffer(void) {
	while (std::cin.get() != '\n')
		;
}
