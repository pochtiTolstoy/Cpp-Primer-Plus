#include <iostream>
#include <cstring>

int main() {
	const int Size = 65;
	const int N_symb = 3; // ',' ' ' '\0'

	char first_name[Size];
	std::cout << "Enter your first name: ";
	std::cin.getline(first_name, Size);

	char last_name[Size];
	std::cout << "Enter your last name: ";
	std::cin.getline(last_name, Size);

	int len1 = strlen(first_name);
	int len2 = strlen(last_name);
	int new_size = len1 + len2 + N_symb;
	char* concat_string = new char[new_size];
	strcpy(concat_string, last_name);
	strcat(concat_string, ", ");
	strcat(concat_string, first_name);

	std::cout << "Here's the information in a single string: " << concat_string << std::endl;

	delete[] concat_string;

	return 0;
}
