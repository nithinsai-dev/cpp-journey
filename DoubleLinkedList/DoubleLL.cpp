#include "DoubleLL.h"
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert at any position (1-based indexing)
    void insertAtPosition(int pos, int val) {
        Node* newNode = new Node(val);

        // Insert at beginning
        if (pos == 1) {
            newNode->next = head;
            if (head != nullptr)
                head->prev = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
            temp = temp->next;

        if (temp ==nullptr) {
            cout << "Invalid Position\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr)
            temp->next->prev = newNode;

        temp->next = newNode;
    }

    // Delete at any position
    void deleteAtPosition(int pos) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        // Delete first node
        if (pos == 1) {
            Node* temp = head;
            head = head->next;

            if (head != nullptr)
                head->prev = nullptr;

            delete temp;
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Invalid Position\n";
            return;
        }

        temp->prev->next = temp->next;

        if (temp->next != nullptr)
            temp->next->prev = temp->prev;

        delete temp;
    }

    // Display forward
    void displayForward() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Display backward
    void displayBackward() {
        if (head == nullptr)
            return;

        Node* temp = head;

        while (temp->next != nullptr)
            temp = temp->next;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }

        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtPosition(1, 10);
    dll.insertAtPosition(2, 20);
    dll.insertAtPosition(3, 30);
    dll.insertAtPosition(2, 15);

    cout << "Forward: ";
    dll.displayForward();

    cout << "Backward: ";
    dll.displayBackward();

    dll.deleteAtPosition(3);

    cout << "After Deletion:\n";

    cout << "Forward: ";
    dll.displayForward();

    cout << "Backward: ";
    dll.displayBackward();

    return 0;
}