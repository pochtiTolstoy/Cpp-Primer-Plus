#include <iostream>
#include <cstring>
#include <cstdlib>

const char* menu_choices = "cptg";

void show_menu(void);
void print_menu_choices(void);
void clear_buffer(void);
void say_cow(void);
void say_pencil(void);
void say_tiger(void);
void say_green(void);
void say_nothing(void);

int main() {
	char ch;
	show_menu();	
	while (std::cin.get(ch) && !strchr(menu_choices, ch)) {
		clear_buffer();
		std::cout << "Please enter a ";
		print_menu_choices();
		std::cout << ": ";
	}
	if (std::cin.fail()) {
		std::cout << "Hmm... smth went wrong.\n";
		exit(EXIT_FAILURE);
	}
	clear_buffer();

	switch (ch) {
		case 'c' : say_cow();
			break;
		case 'p' : say_pencil();
			break;
		case 't' : say_tiger();
			break;
		case 'g' : say_green();
			break;
		default: say_nothing();
			break;
	}

	std::cout << "End of the program.\n";
	
	return 0;
}

void show_menu(void) {
	std::cout << "Please enter one of the following choices:\n";
	std::cout << "c) carnivore    p) pianist\n";
	std::cout << "t) tree         g) game\n";
}

void clear_buffer(void) {
	while (std::cin.get() != '\n')
		continue;
}

void say_cow(void) {
	std::cout << "Cow!\n";
}

void say_pencil(void) {
	std::cout << "Pencil!\n";
}

void say_tiger(void) {
	std::cout << "Tiger!\n";
}

void say_green(void) {
	std::cout << "Green!\n";
}

void say_nothing(void) {
	std::cout << "Hmm... i have nothing cool to say.\n";
}

void print_menu_choices(void) {
	int len = strlen(menu_choices);
	for (int i = 0; i < len; ++i) {
		if (i == len - 1)
			std::cout << "or " << menu_choices[i];
		else
			std::cout << menu_choices[i] << ", ";
	}
}

