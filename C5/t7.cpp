#include <iostream>

const int SIZE = 65;

struct car {
	char company_name[SIZE];
	unsigned int year_of_prod;
};

int main() {
	int number_of_cars;
	std::cout << "Enter how many cars do you want to add into database: ";
	std::cin >> number_of_cars;
	std::cin.get();

	car* p_database = new car[number_of_cars];
	for (int i = 0; i < number_of_cars; ++i) {
		std::cout << "Automobile #" << i + 1 << ":\n";
		std::cout << "Enter name of company: ";
		std::cin.getline(p_database[i].company_name, SIZE);
		std::cout << "Enter year of production: ";
		std::cin >> p_database[i].year_of_prod;
		std::cin.get(); // to read '\n' charachter
	}

	std::cout << "Here is your database:\n";
	for (int i = 0; i < number_of_cars; ++i) {
		std::cout << p_database[i].year_of_prod << ' ' 
							<< p_database[i].company_name << std::endl;
	}

	delete[] p_database;

	return 0;
}
