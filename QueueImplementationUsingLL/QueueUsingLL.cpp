//
// Created by NITHIN SAI on 22-07-2026.
//

#include "QueueUsingLL.h"
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
    Node* front;
    Node* rear;

public :
    Queue() {
        front = rear = nullptr;
    };

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return front->data;
    }

};

int main() {
    Queue q;
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);

    cout << q.peek() << endl;

    q.dequeue();

    cout << q.peek() << endl;

    return 0;
}
