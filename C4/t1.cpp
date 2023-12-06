#include <iostream>

int main() {
	// getline - если хотим читать несколько слов в строке
	// 'A' - 1 - должно дать 'B'

	const int size = 65;

	char first_name[size];
	std::cout << "What is your first name? ";
	std::cin.getline(first_name, size);

	char last_name[size];
	std::cout << "What is your last name? ";
	std::cin.getline(last_name, size);

	char grade;
	std::cout << "What letter grade do you deserve? ";
	std::cin >> grade;
	++grade;

	int age;
	std::cout << "What is your age? ";
	std::cin >> age;

	std::cout << "Name: " << last_name << ", " << first_name << std::endl;
	std::cout << "Grade: " << grade << std::endl;
	std::cout << "Age: " << age << std::endl;


	return 0;
}
