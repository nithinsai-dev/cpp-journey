//
// Created by NITHIN SAI on 24-06-2026.
//

#include "Pointer2.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>

struct rectangle {
    int length;
    int breadth;
};

int main() {

    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct rectangle *p5;

    std::cout << sizeof(p1) << '\n';
    std::cout << sizeof(p2) << '\n';
    std::cout << sizeof(p3) << '\n';
    std::cout << sizeof(p4) << '\n';
    std::cout << sizeof(p5) << '\n';

    //size of a pointer is always constant not dependent on data type , here it is 8bytes

    return 0;
}