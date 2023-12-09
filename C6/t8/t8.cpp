#include <iostream>
#include <fstream>
#include <cstdlib>

const int SIZE = 65;

int main() {
	char filename[SIZE];
	std::cout << "Enter file name: ";
	std::cin >> filename; //read one word

	std::ifstream in;
	in.open(filename);
	if (!in.is_open()) {
		std::cout << "Error. Can't open the file: " << filename << std::endl;
		exit(EXIT_FAILURE);
	}
	
	char ch;
	int cnt = 0;
	while (in.get(ch))
		++cnt;	

	if (in.eof())
		std::cout << "Reach end of file: " << filename << std::endl;
	else if (in.fail())
		std::cout << "Smth went wrong in file: " << filename << std::endl;
	else
		std::cout << "?\n";
	
	std::cout << "There are " << cnt << " symbols in file: " << filename << std::endl;

	in.close();
	return 0;
}
