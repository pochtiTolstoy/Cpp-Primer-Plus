#include <iostream>

static int fcnt = 0;
void strange_print(const char*);
void strange_print(const char*, int);
void print_n_times(const char*, int);

int main() {
	strange_print("Hello!");	
	strange_print("Hell!");
	strange_print("How are you?", 0);
	strange_print("Zero int", 0);
	strange_print("Why are you mad?", 1);
	strange_print("Apple!");
	strange_print("1! ", 10000);
	strange_print("I am tired, bye!");
	std::cout << "Main: function calls - " << fcnt << std::endl;
	return 0;
}

void strange_print(const char* str) {
	++fcnt;	
	std::cout << "Just print one time:\n";
	print_n_times(str, 1);
}

void strange_print(const char* str, int flag) {
	++fcnt;	
	print_n_times(str, flag ? fcnt : 1);
	std::cout << "Function calls: " << fcnt << std::endl;
}

void print_n_times(const char* str, int n) {
	for (int i = 0; i < n; ++i)
		std::cout << str;
	std::cout << '\n';
}
