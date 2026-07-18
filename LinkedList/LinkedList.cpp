#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val) , next(nullptr) {}
};

void insertAtEnd(Node*& head,int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
        return;
    }

     Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp ->next;
    }
    temp->next = newNode;
}

void printNode(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp -> next;
    }
}
int main() {

    int n;
    cin >> n;

    Node* head = nullptr;
    for (int i=0;i<n;i++) {
        int x;
        cin >>x;
        insertAtEnd(head,x);
    }

    printNode(head);

    return 0;
}