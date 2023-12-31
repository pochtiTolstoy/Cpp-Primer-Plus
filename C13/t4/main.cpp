#include <iostream>
#include "port.h"

int main() {
    Port obj1 = Port("Gallo", "tawny", 20);
    Port obj2 = obj1;
    Port obj3;
    obj3 = obj1;

    obj2 += 10;
    obj3 -= 10;

    std::cout << obj1 << std::endl;
    std::cout << obj2 << std::endl;
    obj3.Show();
    std::cout << std::endl;

    VintagePort obj4 = VintagePort("45 Cockburn", 40, "Old Velvet", 1888);
    VintagePort obj5 = obj4;
    VintagePort obj6;
    obj6 = obj4;
    obj5 += 10;
    obj6 -= 10;

    std::cout << obj4 << std::endl;
    std::cout << obj5 << std::endl;
    obj6.Show();
    std::cout << std::endl;

    return 0;
}
