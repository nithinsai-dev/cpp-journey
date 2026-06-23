//
// Created by NITHIN SAI on 22-06-2026.
//

#include "structures.h"
#include <cstdio>
#include <iostream>

using namespace std;

struct rectangle {
    int length;
    int breadth;
    char x;
}; //r1,r2,r3.......

// struct rectangle r2,r4,r5,r6.......; <- can be declared outside the main function,  and it is a global variable

int main() {

    struct rectangle r1 = {15,10};

    printf("%d\n" , sizeof(rectangle));
    cout << "Hello World !" << endl;

    return 0;
}