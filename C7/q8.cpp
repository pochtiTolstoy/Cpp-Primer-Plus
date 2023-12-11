#include <iostream>

int replace(char* str, char c1, char c2);

int main() {
	char st[] = "Hello, Hell. Helicopters and Heroes";
	std::cout << "String before replace: " << st << std::endl;
	int cnt = replace(st, 'H', '0'); 
	std::cout << "String after replace: " << st << std::endl;
	std::cout << "Amount of changes: " << cnt << std::endl;
	return 0;
}

int replace(char* str, char c1, char c2) {
	int cnt = 0;
	while (*str) {
		*str++ = (*str == c1) ? (++cnt, c2) : *str;
	}
	return cnt;
}
