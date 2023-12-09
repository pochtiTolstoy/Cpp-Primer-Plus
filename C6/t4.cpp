#include <iostream>
#include <cstdlib>
#define QUIT 'q'

const int STRLEN = 129;
const int SIZE = 4;

struct bop {
	char fullname[STRLEN];
	char title[STRLEN];
	char bopname[STRLEN];
	int preference;
};

void show_menu(void);
void clear_buffer(void);
void blank_call(void);
void display_by_name(const struct bop data[], int n);
void display_by_title(const struct bop data[], int n);
void display_by_bopname(const struct bop data[], int n);
void display_by_preference(const struct bop data[], int n);

int main() {
	bop data[SIZE] = {
		{ "Wimp", "Middle", "103", 1 },
		{ "Raki", "Junior", "2550", 0 },
		{ "Hoppy", "DS", "0053", 1 },
		{ "Celia", "Designer", "1004", 2 }
	};
	
	show_menu();
	char choice;
	while (std::cin.get(choice) && choice != QUIT) {
		clear_buffer();	
		switch (choice)	{
			case 'a' : display_by_name(data, SIZE);
				break;
			case 'b' : display_by_title(data, SIZE);
				break;
			case 'c' : display_by_bopname(data, SIZE);
				break;
			case 'd' : display_by_preference(data, SIZE);
				break;
			default : blank_call();
				break;
		}
		std::cout << "Next choice: ";
	}
	if (std::cin.fail()) {
		std::cout << "Something went wrong...\n";
		exit(EXIT_FAILURE);
	}
	clear_buffer();


	return 0;
}

void show_menu(void) {
	std::cout << "a. display by name      b. display by title\n";
	std::cout << "c. display by bopname   d. display by preference\n";
	std::cout << "q. quit\n";
}

void clear_buffer(void) {
	while (std::cin.get() != '\n')
		continue;
}

void blank_call(void) {
	std::cout << "I don't know about this value yet.\n";
}

void display_by_name(const struct bop data[], int n) {
	for (int i = 0; i < n; ++i)
		std::cout << data[i].fullname << std::endl; 
}

void display_by_title(const struct bop data[], int n) {
	for (int i = 0; i < n; ++i)
		std::cout << data[i].title << std::endl;
}

void display_by_bopname(const struct bop data[], int n) {
	for (int i = 0; i < n; ++i)
		std::cout << data[i].bopname << std::endl;
}

void display_by_preference(const struct bop data[], int n) {
	for (int i = 0; i < n; ++i) {
		switch (data[i].preference) {
			case 0 : std::cout << data[i].fullname << std::endl;
				break;
			case 1 : std::cout << data[i].title << std::endl;
				break;
			case 2 : std::cout << data[i].bopname << std::endl;
				break;
			default : 
				std::cout << "Wrong preference value!\n";
				return;
		}
	}
}
