//
// Created by NITHIN SAI on 22-07-2026.
//

#include "queueImplementaionArray.h"
#include <iostream>

using namespace std;

class queue {
    int arr[100];
    int front;
    int rear;

public:
    queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int val) {
        if (rear > 99) {
            cout << "Queue Overflow" << endl;
            return;
        }

        if (front == -1) {
            front =0;
        }

        arr[++rear] = val;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue empty" << endl;
            return;
        }

        front++;
    }

    int peek() {
        if (front == -1 || front > rear) {
            cout << "Queue empty" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main() {
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;

    return 0;
}