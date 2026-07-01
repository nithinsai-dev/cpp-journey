//
// Created by NITHIN SAI on 01-07-2026.
//

#include "StructAsParameter.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct rectangle {
    int length;
    int breadth;
};

// void fun(struct rectangle rect) {
//     rect.length++;
//     rect.breadth++;
//     cout << "Length : " << rect.length << endl  << "Breadth : " << rect.breadth << endl;
// }
//
// int main() {
//
//     struct rectangle r1 = {10,5};
//     printf("Length : %d \nBreadth : %d \n",r1.length,r1.breadth);
//
//     fun(r1);
//
//
//     return 0;
// }

// void fun(struct rectangle *p) {
//     p->length++;
//     p->breadth++;
//     cout << "Length : " << p->length << endl  << "Breadth : " << p->breadth << endl;
// }
//
// int main() {
//
//     struct rectangle r1 = {10,5};
//     fun(&r1);
//     printf("Length : %d \nBreadth : %d \n",r1.length,r1.breadth);
//
//
//     return 0;
// }

struct rectangle *fun(){
    struct rectangle *p;
    p = new rectangle; // -> in C++
    // p = (struct rectangle *)malloc(sizeof(struct rectangle)); -> in C

    p->length = 10;
    p->breadth = 7;

    return p;
}

int main() {
    struct rectangle *ptr = fun();
    cout << ptr -> length << endl;

    return 0;
}

