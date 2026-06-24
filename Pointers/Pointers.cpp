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

    // int arr[5] = {2,4,6,8,10};
    // int *pArr;
    // pArr = arr;     // -> no need ampresand(&) coz array is already stored as reference

    // for (int i=0;i<5;i++) {
    //     cout << pArr[i] << endl;
    // }

    int *p;
    p = (int*) malloc(5*sizeof(int));
    p[0] = 1; p[1] = 2; p[2] = 3; p[3] = 4; p[4] = 5;

    for (int i=0;i<5;i++) {
        cout << p[i] << endl;
    }

    free(p);
    return 0;
}

void birthday(int* age) {
    //pass by reference
    (*age)++;
}