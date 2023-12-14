#include <iostream>
#include <cstring>

void iquote(int);
void iquote(double);
void iquote(std::string);

int main() {
	int n1 = 1;
	double n2 = 1999.23;
	std::string str = "Hello World!";
	iquote(n1);
	iquote(n2);
	iquote(str);
	return 0;
}

void iquote(int num) {
	std::cout << '\"' << num << '\"' << std::endl;	
}

void iquote(double num) {
	std::cout << '\"' << num << '\"' << std::endl;	
}

void iquote(std::string str) {
	std::cout << '\"' << str << '\"' << std::endl;	
}
