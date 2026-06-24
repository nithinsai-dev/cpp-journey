//
// Created by NITHIN SAI on 24-06-2026.
//

#include "P2S.h"
#include <iostream>
#include <cstdio>

using namespace std;

struct rectangle {
    int length;
    int breadth;
};

int main() {

    struct rectangle *p;
    // p = new rectangle;
    // *p = {10,5};
    // cout << p->length << endl; -> creatung memory dynamically in cpp (in heap)

    p = (struct rectangle*)malloc(sizeof(struct rectangle));
    p -> length = 10;
    p -> breadth = 7;

    printf(" %d   %d ",p->length,p->breadth); // dynamically creating memory in heap in C

    return 0;
}
