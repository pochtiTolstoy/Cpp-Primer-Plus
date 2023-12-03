#include <iostream>

void mice_function(void);
void run_function(void);

int main() {
	mice_function();
	mice_function();
	run_function();
	run_function();
	return 0;
}

void mice_function(void) {
	std::cout << "Three blind mice" << std::endl;
}

void run_function(void) {
	std::cout << "See how they run" << std::endl;
}
