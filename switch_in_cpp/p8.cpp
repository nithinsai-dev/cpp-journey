//
// Created by NITHIN SAI on 12-06-2026.
//

#include "p8.h";
#include <iostream>;

int main() {

    int number;
    std::cout << "enter a number (0-6) : ";
    std::cin >> number;

    switch (number) {
        case 0:
            std::cout << "Monday";
            break;
        case 1:
            std::cout << "Tuesday";
            break;
        case 2:
            std::cout << "Wednesday";
            break;
        case 3:
            std::cout << "Thursday";
            break;
        case 4:
            std::cout << "Friday";
            break;
        case 5:
            std::cout << "Saturday";
            break;
        case 6:
            std::cout << "Saturday";
            break;
        case 7:
            std::cout << "Sunday";
            break;
        default:
            std::cout << "Enter a number";
    }

    return 0;
}
