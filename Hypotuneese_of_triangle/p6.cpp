//
// Created by NITHIN SAI on 12-06-2026.
//

#include "p6.h";
#include <iostream>;
#include <cmath>;

int main() {
    double a;
    double b;
    double c;

    std::cout << "enter the number : ";
    std::cin >> a;
    std::cout << "enter the number : ";
    std::cin >> b;

    a = pow(a,2);
    b = pow(b,2);
    c = sqrt(a+b);

    std::cout << "The hypoutenese is " << c;

    return 0;
}
