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
	Pizza* pcustomer_pizza = new Pizza;
	add_pizza(pcustomer_pizza);
	print_pizza(pcustomer_pizza);

	delete pcustomer_pizza;
	return 0;
}

void add_pizza(struct Pizza* ppizza) {
	std::cout << "Enter diameter of pizza: ";
	std::cin >> ppizza->diameter;
	std::cin.get();                         // read symbol '\n'
	std::cout << "Enter name of pizza: ";
	std::cin.getline(ppizza->name, Size);
	std::cout << "Enter weight of pizza: ";
	std::cin >> ppizza->weight;
	std::cin.get();                         //read symbol '\n'
}

void print_pizza(const struct Pizza* ppizza) {
	std::cout << "Pizza! Name: " << ppizza->name
						<< ", diameter: "   << ppizza->diameter
						<< ", weight: "     << ppizza->weight 
						<< std::endl;
}
