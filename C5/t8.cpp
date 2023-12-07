#include <iostream>
#include <cstring>

const int SIZE = 129;

int main() {
	char word[SIZE] = {};	
	int words_counter = 0;

	std::cout << "Enter words (enter word done to end a programm): ";
	while (std::cin >> word, strcmp(word, "done"))
		++words_counter;
	std::cout << "You have entered " << words_counter << " words.\n";

	while (std::cin.get() != '\n')
		continue;

	return 0;
}
