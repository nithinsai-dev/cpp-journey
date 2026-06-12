//
// Created by NITHIN SAI on 12-06-2026.
//

#include "Temp_converter.h";
#include <iostream>;

int main() {
    char unit;
    double temp;

    std::cout << "***************Temperature Conversion*****************" << '\n';
    std::cout << "Farenheit(F) " << '\n';
    std::cout << "Celsius(C)" << '\n';
    std::cout << "Which unit you want to convert : ";
    std::cin >> unit;


    if (unit == 'F' || unit == 'f') {
        std::cout << "Enter the temperature(Celsius) : ";
        std::cin >> temp;

        temp = (1.8*temp) + 32.0;
        std::cout << "The temperature is " << temp << 'F' << '\n';
    } else if (unit == 'C' || unit =='c'){
        std::cout << "Enter the temperature(Farenheit) : ";
        std::cin >> temp;

        temp = (temp-32.0)/1.8;
        std::cout << "The temperature is " << temp << 'C' << '\n';
     } else {
         std::cout << "Please enter omly C or F";
     }
    std::cout << "******************************************************";

    return 0;
}

