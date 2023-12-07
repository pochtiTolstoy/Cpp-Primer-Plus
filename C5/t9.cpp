#include <iostream>
#include <string>

int main() {
	std::string word;
	int word_counter = 0;

	std::cout << "Enter words (or enter done to end a program): ";
	while (std::cin >> word && word != "done")
		++word_counter;

	while (std::cin.get() != '\n')
		continue;

	std::cout << "You have entered " << word_counter << " words." << std::endl;
	return 0;
}
