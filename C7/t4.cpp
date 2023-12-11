#include <iostream>

long double probability(unsigned numbers, unsigned picks);

int main() {
	std::cout << "The probability of winning in game of 1-47 "
							 "with 5 picks and one supernumber in 1-27 is:\n";
	std::cout << probability(47, 5) * probability(27, 1);
	return 0;
}

long double probability(unsigned numbers, unsigned picks) {
	long double result = 1.0;
	long double n;
	unsigned p;
	for (n = numbers, p = picks; p > 0; --n, --p)
		result *= n / p;
	return result;
}
