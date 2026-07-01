//
// Created by NITHIN SAI on 01-07-2026.
//

#include "TemplateClasses.h"
#include <iostream>

using namespace std;

template <class T>
class Arithmetic {
    private:
        T a;
        T b;
    public:
        Arithmetic(T a,T b);
        int add();
        int subtract();
};

template <class T>
Arithmetic<T>::Arithmetic(T a,T b) {
    this->a = a;
    this->b = b;
}

template <class T>
int Arithmetic<T>::add() {
    T c;
    c = a+b;
    return c;
}

template <class T>
int Arithmetic<T>::subtract() {
    T c;
    c = a-b;
    return c;
}


int main() {

    Arithmetic<int> a(10,5);
    cout<<a.add()<<endl;
    cout << a.subtract() << endl;

    return 0;
}
