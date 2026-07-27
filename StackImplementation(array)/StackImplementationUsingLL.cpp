//
// Created by NITHIN SAI on 21-07-2026.
//

#include "solution.h"
#include <iostream>

using namespace std;

class stack {
    int arr[100];
    int top;
public:
    stack() {
        top = -1;
    }

    void push(int x) {
        if (top==99) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (top==-1) {
            cout << "Stack underflow" << endl;
            return;
        }
        top--;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 99;
    }
};

int main() {

    stack s;
    s.push(1);
    s.push(2);
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;

    cout << s.isEmpty() << endl;
    cout << s.isFull() << endl;


    return 0;
}
