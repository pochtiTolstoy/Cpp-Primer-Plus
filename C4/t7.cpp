#include <iostream>

const int Size = 65;

struct Pizza {
	char name[Size];
	double diameter;
	double weight;
};

void print_pizza(const struct Pizza*);
void add_pizza(struct Pizza*);

int main() {
	Pizza customer_pizza;
	add_pizza(&customer_pizza);
	print_pizza(&customer_pizza);

	return 0;
}

void add_pizza(struct Pizza* ppizza) {
	std::cout << "Enter name of pizza: ";
	std::cin.getline(ppizza->name, Size);
	std::cout << "Enter diameter of pizza: ";
	std::cin >> ppizza->diameter;
	std::cout << "Enter weight of pizza: ";
	std::cin >> ppizza->weight;
}

void print_pizza(const struct Pizza* ppizza) {
	std::cout << "Pizza! Name: " << ppizza->name
						<< ", diameter: "   << ppizza->diameter
						<< ", weight: "     << ppizza->weight 
						<< std::endl;
}
