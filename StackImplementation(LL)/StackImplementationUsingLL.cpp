//
// Created by NITHIN SAI on 21-07-2026.
//

#include "StackImplementationUsingLL.h"
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) : data(x),next(nullptr) {}
};

class stack {
    Node* top;

public:
    stack() {
        top = nullptr;
    }

    void push(int x) {
        Node* newNode= new Node(x);

        newNode -> next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack underflow" << endl;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack empty" << endl;
            return -1;
        }

        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {

    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    cout << s.isEmpty() << endl;

    return 0;
}
