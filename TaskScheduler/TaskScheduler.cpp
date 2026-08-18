//
// Created by NITHIN SAI on 18-08-2026.
//

#include "TaskScheduler.h"
#include <iostream>

using namespace std;

class circularDeque {
private:
    int front;
    int rear;
    int size;
    int capacity;
    int* arr;
public:
    circularDeque(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front =0;
        rear=-1;
        size=0;
    }
    bool isEmpty() {
        return size==0;
    }
    bool isFull() {
        return size==capacity;
    }
    void insertRear(int value) {
        if (isFull()) {
            cout<<"Queue is full"<<endl;
            return;
        }
        rear = (rear+1)%capacity;
        arr[rear] = value;
        size++;
    }
    void insertFront(int value) {
        if (isFull()) {
            cout<<"Queue is full"<<endl;
            return;
        }
        front=(front-1+capacity)%capacity;
        arr[front] = value;
        size++;
    }
    void deleteRear() {
        if (isEmpty()) {
            cout << "Queue is empty"<<endl;
            return;
        }
        rear = (rear-1+capacity)%capacity;
        size--;
    }
    void deleteFront() {
        if (isEmpty()) {
            cout << "Queue is empty"<<endl;
            return;
        }
        front=(front+1)%capacity;
        size--;
    }
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }
};

int main() {



    return 0;
}
