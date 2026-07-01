//
// Created by NITHIN SAI on 01-07-2026.
//

#include "StructuresAndFunctions.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct rectangle {
    int length;
    int breadth;
};

void initialize(struct rectangle* r,int length,int breadth);
void area(struct rectangle r);
void changeLength(struct rectangle* r,int length) ;

int main() {

    struct rectangle r;

    initialize(&r,15,7);
    area(r);
    changeLength(&r,19);

    return 0;
}

void initialize(struct rectangle* r,int length,int breadth) {
    r -> length = length;
    r -> breadth = breadth;
    printf("length : %d\nbreadth : %d\n" ,r -> length,r -> breadth);
}

void area(struct rectangle r) {
    cout << (r.length)*(r.breadth) << endl;
}

void changeLength(struct rectangle* r,int length) {
    r->length = length;
    printf("length : %d\nbreadth : %d\n" ,r -> length,r -> breadth);
}

