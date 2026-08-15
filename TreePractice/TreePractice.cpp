//
// Created by NITHIN SAI on 15-08-2026.
//

#include "TreePractice.h"
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

//height of binary tree
int height(Node* root) {
    if (root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}

//Is 2 trees identical
bool isIdentical(Node* a, Node* b) {
    if (a == nullptr && b == nullptr) return true;
    if (a == nullptr || b == nullptr) return false;
    return (a->data == b->data) &&
           isIdentical(a->left, b->left) &&
           isIdentical(a->right, b->right);
}

//If given trees mirror each other
bool isMirror(Node* a, Node* b) {
    if (a == nullptr && b == nullptr) return true;
    if (a == nullptr || b == nullptr) return false;
    return (a->data == b->data) &&
           isMirror(a->left, b->right) &&
           isMirror(a->right, b->left);
}

//print node at a given distance
void printNodesAtDistance(Node* root, int k) {
    if (root == nullptr) return;
    if (k == 0) {
        cout << root->data << " ";
        return;
    }
    printNodesAtDistance(root->left, k - 1);
    printNodesAtDistance(root->right, k - 1);
}


