#include <iostream>
#include <string>

int main() {
	std::string first_name;
	std::cout << "Enter your first name: ";
	std::cin >> first_name;

	std::string last_name;
	std::cout << "Enter your last name: ";
	std::cin >> last_name;

	std::string concat_string = last_name + ", " + first_name;
	std::cout << "Here's the information in a single string: " << concat_string << std::endl;
	return 0;
}
