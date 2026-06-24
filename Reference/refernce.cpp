//
// Created by NITHIN SAI on 24-06-2026.
//

#include "refernce.h"
#include <iostream>

using namespace std;

int main() {
    int a = 10;
    int &r = a; // -> both are same variable

    //cannot change the reference;

    cout << r << '\n';
    cout << a << '\n';

    r = 25;

    cout << r << '\n';
    cout << a << '\n';

    return 0;
}
