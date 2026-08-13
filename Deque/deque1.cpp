#include <iostream>
using namespace std;

class Deque {
    int* arr;
    int size;
    int capacity;

public:

    Deque(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        size = 0;
    }

    // 1. Insert at Front
    void insertFront(int key) {

        if (size == capacity) {
            cout << "Deque is full" << endl;
            return;
        }

        // Shift all elements one position to the right
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = key;
        size++;
    }

    // 2. Insert at Rear
    void insertRear(int key) {

        if (size == capacity) {
            cout << "Deque is full" << endl;
            return;
        }

        arr[size] = key;
        size++;
    }

    // 3. Delete from Front
    void deleteFront() {

        if (size == 0) {
            cout << "Deque is empty" << endl;
            return;
        }

        cout << "Deleted: " << arr[0] << endl;

        // Shift all elements one position to the left
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    // 4. Delete from Rear
    void deleteRear() {

        if (size == 0) {
            cout << "Deque is empty" << endl;
            return;
        }

        cout << "Deleted: " << arr[size - 1] << endl;

        size--;
    }

    // Display
    void display() {

        if (size == 0) {
            cout << "Deque is empty" << endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    ~Deque() {
        delete[] arr;
    }
};

int main() {

    Deque dq(5);

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertRear(30);

    dq.display();
    // 10 20 30

    dq.insertFront(5);

    dq.display();
    // 5 10 20 30

    dq.deleteFront();

    dq.display();
    // 10 20 30

    dq.deleteRear();

    dq.display();
    // 10 20

    return 0;
}