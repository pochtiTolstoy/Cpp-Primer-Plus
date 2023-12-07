#include <iostream>

int main() {
	int num1, num2;
	std::cout << "Enter the first number: ";
	std::cin >> num1;
	std::cout << "Enter the second number: ";
	std::cin >> num2;
	std::cin.get(); // to read '\n' from input stream
	int sum = 0;
	for (int i = num1; i <= num2; ++i)
		sum += i;
	std::cout << "Sum of range [" << num1 
						<< ", " << num2 << "] is " 
						<< sum << ".\n";
	return 0;
}
