//
// Created by NITHIN SAI on 23-06-2026.
//

#include "Pointers.h"
#include <cstdio>
#include <iostream>

using namespace std;

void birthday(int* age);

int main() {

    int age = 10;
    int *pAge = &age;

    birthday(&age);
    cout << "You are " << age << " years old\n";

    return 0;
}

void birthday(int* age) {
    //pass by reference
    (*age)++;
}