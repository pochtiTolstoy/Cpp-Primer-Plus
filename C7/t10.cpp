#include <iostream>
#include <cstdlib>
#include <cmath>

typedef double (*PFC)(double, double); // Pointer to calculate function
typedef void (*PFS)(double, double);   // Pointer to show function

struct Calc_package {
	PFC* f_calc;         // Pointer for memory allocation
	PFS* f_show;
	double* results;
	int items = 0;
};

//---------------------------------------------------------------
const int SIZE = 4;
void init_basic_package(Calc_package* p_calc);
void delete_package(Calc_package* p_calc);
double calculate(double, double, PFC);
void package_calc(double, double, const Calc_package*);
void show_results(const Calc_package* p_calc);

double add(double x, double y);
double sub(double x, double y);
double mult(double x, double y);
double div(double x, double y);

void show_add(double x, double y);
void show_sub(double x, double y);
void show_mult(double x, double y);
void show_div(double x, double y);
void clear_buffer(void);

// tracking functions is global scope
PFC glob_calc[SIZE] = { add, sub, mult, div };
PFS glob_show[SIZE] = { show_add, show_sub, show_mult, show_div };
//---------------------------------------------------------------
void start_calc(Calc_package* p_calc);


int main() {
	Calc_package basic_calc; // Declaration
	init_basic_package(&basic_calc); // Defenition
	std::cout << "Testing basic package:\n";
	start_calc(&basic_calc);
	show_results(&basic_calc); // DELETE
	delete_package(&basic_calc); // Free memory allocated in package



	return 0;
}

void start_calc(Calc_package* p_calc) {
	std::cout << "Enter two real number (q to quit): ";
	double a, b;
	while ((std::cin >> a >> b)) {
		package_calc(a, b, p_calc);
		std::cout << "Enter two next numbers: ";
	}
	if (std::cin.fail())
		std::cin.clear();
	clear_buffer();
}

void package_calc(double x, double y, const Calc_package* p_calc) {
	if (p_calc->items == 0) {
		std::cout << "Where is no functions in package.\n\n";
		return;
	}
	for (int i = 0; i < p_calc->items; ++i) {
		p_calc->f_show[i](x, y);
		p_calc->results[i] = calculate(x, y, p_calc->f_calc[i]);
		std::cout << p_calc->results[i] << std::endl;
	}
	std::cout << std::endl;
}

void show_results(const Calc_package* p_calc) {
	if (p_calc->items == 0)
		return;
	std::cout << "Results of package:\n";
	for (int i = 0; i < p_calc->items; ++i)
		std::cout << p_calc->results[i] << ' ';
	std::cout << std::endl;
}

void init_basic_package(Calc_package* p_calc) {
	static const int FUN_NUM = 4;
	if (FUN_NUM > SIZE) {
		std::cerr << "Error: In function database only " << SIZE << " functions are availible.\n";
		p_calc->items = 0;
		return;	
	}
	if (p_calc->items != 0) {
		std::cerr << "Error. Can't initialize initialized memory!\n" 
							<< p_calc->items << " function in package already.\n";
		return;
	}
	p_calc->items = FUN_NUM;
	p_calc->f_calc = new PFC[FUN_NUM];
	p_calc->f_show = new PFS[FUN_NUM];
	p_calc->results = new double[FUN_NUM];
	for (int i = 0; i < FUN_NUM; ++i) {
		p_calc->f_calc[i] = glob_calc[i];
		p_calc->f_show[i] = glob_show[i];
	}
}

void delete_package(Calc_package* p_calc) {
	if (p_calc->items = 0)
		return;
	delete[] p_calc->f_calc;
	delete[] p_calc->f_show;
	delete[] p_calc->results;
	p_calc->items = 0;
}

double add(double x, double y) {
	return x + y;
}

double sub(double x, double y) {
	return x - y;
}

double mult(double x, double y) {
	return x * y;
}

double div(double x, double y) {
	if (y == 0)
		return std::nan("");
	return x / y;
}

void show_add(double x, double y) {
	std::cout << x << " + " << y << " = ";
}

void show_sub(double x, double y) {
	std::cout << x << " - " << y << " = ";
}

void show_mult(double x, double y) {
	std::cout << x << " * " << y << " = ";
}

void show_div(double x, double y) {
	std::cout << x << " / " << y << " = ";
}

double calculate(double a, double b, PFC pf) {
	return (*pf)(a, b);	
}

void clear_buffer(void) {
	while (std::cin.get() != '\n')
		;
}
