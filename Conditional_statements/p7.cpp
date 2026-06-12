//
// Created by NITHIN SAI on 12-06-2026.
//

#include "p7.h"
#include <iostream>;

std::ostream operator>>(const std::ostream & lhs, char * str);

int main() {

    int age;
    std::cout << "enter ur age : ";
    std::cin >> age;

    if (age >=100 ) {
        std::cout << "You are too old";
    } else if (age > 0 && age <=100) {
        std::cout << "You can enter ";
    } else if (age < 0) {
        std::cout << "You are not born yet";
    } else {
        std::cout << "You cannot enter";
    }

    return 0;
}
