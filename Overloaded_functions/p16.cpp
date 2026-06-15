//
// Created by NITHIN SAI on 13-06-2026.
//

#include "p16.h"
#include <iostream>

using namespace std;

int add(int num1,int num2) {
    return num1 + num2;
}

int add(int num1,int num2,int num3) {
    return num1+num2+num3;
}

int add(int num1,int num2,int num3,int num4) {
    return num1+num2+num3+num4;
}


int main() {


    cout << add(1,2);
    cout << add(1,2,3);
    cout << add(1,2,3,4);

    return 0;
}