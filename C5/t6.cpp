#include <iostream>

const int Years_range = 3;
const int Months_in_year = 12;
const char* months_name[Months_in_year] = {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

int main() {
	int data_sales[Years_range][Months_in_year] = {0};
	
	// Запрашиваем год, с котрого начинается сбор данных
	int start_year;
	std::cout << "Enter the current year: ";
	std::cin >> start_year;

	// Собираем данные из пользовательского ввода о продажах
	for (int year = start_year; year < start_year + Years_range; ++year) {
		std::cout << "Year: " << year << std::endl;
		for (int month = 0; month < Months_in_year; ++month) {
			std::cout << "-- Month: " << months_name[month] << ", enter sales: ";
			std::cin >> data_sales[year - start_year][month];
		}
	}
	std::cin.get();

	// Выводим статистику по собранным данным
	int all_sales = 0;
	int sales_per_year = 0;

	std::cout << std::endl << "Statistics in period of " 
						<< start_year << " - " 
						<< start_year + Years_range << ":\n"; 
						
	for (int year = 0; year < Years_range; ++year) {
		sales_per_year = 0;
		for (int month = 0; month < Months_in_year; ++month) {
			sales_per_year += data_sales[year][month];
		}
		std::cout << "Year: " << start_year + year << ", total sales: " << sales_per_year << std::endl;
		all_sales += sales_per_year;
	}

	std::cout << "Total sales from " 
						<< start_year << " to " 
						<< start_year + Years_range 
						<< ": " << all_sales << std::endl;

	return 0;
}
