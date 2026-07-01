//
// Created by NITHIN SAI on 01-07-2026.
//

#include "ClassesAndConstructors.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Rectangle {
    private:
        int length;
        int breadth;

    public:
        Rectangle() {
            length=0;
            breadth=0;
        }
        Rectangle(int l,int b) {
            length = l;
            breadth = b;
        }
        int area() {
            return length*breadth;
        }
        int perimeter() {
            return 2*(length+breadth);
        }
        void setLength(int l) {
            length = l;
        }
        void setBreadth(int b) {
            breadth = b;
        }
        ~Rectangle() {
            cout << "Destructor";
        }
};

int main() {

    Rectangle rect;
    rect.setLength(10);
    rect.setBreadth(10);
    cout << rect.area() << endl;
    cout << rect.perimeter() << endl;


    return 0;
}
