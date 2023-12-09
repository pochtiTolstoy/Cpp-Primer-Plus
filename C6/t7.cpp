#include <iostream>
#include <cstring>
#include <cctype>

const int SIZE = 129;
const char* alph_vowels = "aeiouy";
	
int main() {
	char word[SIZE];
	int vowels, consonants, others;
	vowels = consonants = others = 0;
	std::cout << "Enter words (q to quit):\n";
	while (std::cin >> word && (word[0] != 'q' || word[1] != '\0')) {
		if (isalpha(word[0])) {
			if (strchr(alph_vowels, tolower(word[0])))
				++vowels;
			else
				++consonants;
		} else
			++others;
	}

	std::cout << vowels << " words beginning with vowels\n";
	std::cout << consonants << " words beginning with consonants\n";
	std::cout << others << " others\n";

	return 0;
}
