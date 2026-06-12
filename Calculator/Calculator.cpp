//
// Created by NITHIN SAI on 12-06-2026.
//

#include "Calculator.h"
#include <iostream>

int main() {

    char op;
    double num1;
    double num2;
    double result;

    std::cout << "******************Calculator******************" << '\n';

    std::cout << "Enter either (+ - * /) : ";
    std::cin >> op;

    std::cout << "Enter #1 : ";
    std::cin >> num1;

    std::cout  << "Enter #2 : ";
    std::cin >> num2;

    switch (op) {
        case '+':
            result =  num1 +  num2;
            std::cout << "Result is : " << result << '\n';
            break;
        case '-':
            result =  num1 -  num2;
            std::cout << "Result is : " << result << '\n';
            break;
        case '*':
            result =  num1 *  num2;
            std::cout << "Result is : " << result << '\n';
            break;
        case '/':
            result =  num1 /  num2;
            std::cout << "Result is : " << result << '\n';
            break;
        default :
            std::cout << "Enter the valid operator!!" << '\n';
            break;
    }

    std::cout << "**********************************************";

    return 0;
}

