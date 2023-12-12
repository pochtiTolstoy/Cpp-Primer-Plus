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
const int Size_basic = 4;
const int Size_trig = 3;
void init_basic_package(Calc_package* p_calc);
void init_trig_package(Calc_package* p_calc);
void delete_package(Calc_package* p_calc);
double calculate(double, double, PFC);
void package_calc(double, double, const Calc_package*);
void show_results(const Calc_package* p_calc);

double add(double, double);
double sub(double, double);
double mult(double, double);
double div(double, double);

double msin(double, double);
double mcos(double, double);
double mtan(double, double);

void show_msin(double, double);
void show_mcos(double, double);
void show_mtan(double, double);

void show_add(double, double);
void show_sub(double, double);
void show_mult(double, double);
void show_div(double, double);
void clear_buffer(void);

// tracking functions is global scope
PFC glob_calc_basic[Size_basic] = { add, sub, mult, div };
PFS glob_show_basic[Size_basic] = { show_add, show_sub, show_mult, show_div };
PFC glob_calc_trig[Size_trig] = { msin, mcos, mtan };
PFS glob_show_trig[Size_trig] = { show_msin, show_mcos, show_mtan };
//---------------------------------------------------------------
void start_calc(Calc_package* p_calc);
bool package_alloc(Calc_package* p_calc, int size);


int main() {
	Calc_package basic_calc; // Declaration
	init_basic_package(&basic_calc); // Defenition
	std::cout << "Testing basic package:\n";
	start_calc(&basic_calc);
	show_results(&basic_calc); // DELETE
	delete_package(&basic_calc); // Free memory allocated in package

	Calc_package trig_calc; // Declaration
	init_trig_package(&trig_calc);
	std::cout << "Testing trig package:\n";
	start_calc(&trig_calc);
	show_results(&trig_calc);
	delete_package(&trig_calc);

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
	const int FUN_NUM = 4;
	if (FUN_NUM > Size_basic) {
		std::cerr << "Error: In function database only " << Size_basic << " functions are availible.\n";
		p_calc->items = 0;
		return;	
	}
	if (!package_alloc(p_calc, FUN_NUM))
		return;
	for (int i = 0; i < FUN_NUM; ++i) {
		p_calc->f_calc[i] = glob_calc_basic[i];
		p_calc->f_show[i] = glob_show_basic[i];
	}
}

void init_trig_package(Calc_package* p_calc) {
	const int FUN_NUM = 3;
	if (FUN_NUM > Size_trig) {
		std::cerr << "Error: In function database only " << Size_basic << " functions are availible.\n";
		p_calc->items = 0;
		return;	
	}
	if (!package_alloc(p_calc, FUN_NUM))
		return;
	for (int i = 0; i < FUN_NUM; ++i) {
		p_calc->f_calc[i] = glob_calc_trig[i];
		p_calc->f_show[i] = glob_show_trig[i];
	}
}

bool package_alloc(Calc_package* p_calc, int size) {
	if (p_calc->items != 0) {
		std::cerr << "Error. Can't initialize initialized memory!\n" 
							<< p_calc->items << " function in package already.\n";
		return false;
	}
	p_calc->items = size;
	p_calc->f_calc = new PFC[size];
	p_calc->f_show = new PFS[size];
	p_calc->results = new double[size];
	return true;
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

double msin(double x, double y) {
	return std::sin(x);
}

double mcos(double x, double y) {
	return std::cos(x);
}

double mtan(double x, double y) {
	return std::tan(x);
}

void show_msin(double x, double y) {
	std::cout << "sin(" << x << ") = ";
}

void show_mcos(double x, double y) {
	std::cout << "cos(" << x << ") = ";
}

void show_mtan(double x, double y) {
	std::cout << "tan(" << x << ") = ";
}

double calculate(double a, double b, PFC pf) {
	return (*pf)(a, b);	
}

void clear_buffer(void) {
	while (std::cin.get() != '\n')
		;
}
