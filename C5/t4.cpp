#include <iostream>

const float Dafna_start_capital = 100.0f;
const float Cleo_start_capital = 100.0f;
const float Dafna_percent = 0.1f;
const float Cleo_percent = 0.05f;

const int max_ticks = 100;

int main() {
	float Dafna_balance = Dafna_start_capital;
	float Cleo_balance = Cleo_start_capital;
	int years = 0;

	while (Cleo_balance <= Dafna_balance && years < max_ticks) {
		Dafna_balance += Dafna_start_capital * Dafna_percent; 
		Cleo_balance += Cleo_balance * Cleo_percent;
		++years;
	}

	if (years >= max_ticks) {
		std::cout << "Time goes so fast... i want to sleep. Bye.\n";
	} else {
		std::cout << "After " << years << " years: Dafna - " << Dafna_balance 
							<< ", Cleo - " << Cleo_balance << std::endl;
		float difference = Cleo_balance - Dafna_balance;
		std::cout << "Difference: " << difference << std::endl;
	}
	return 0;
}
