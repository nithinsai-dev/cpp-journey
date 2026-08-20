//
// Created by NITHIN SAI on 20-08-2026.
//

#include "BST.h"
#include <iostream>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

TreeNode* insert(TreeNode* root, int value) {

    if (root == NULL) {
        return new TreeNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorder(TreeNode* root) {

    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    TreeNode* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder: ";
    inorder(root);

    return 0;
}

// Binary Tree:
// - Each node can have at most 2 children.
// - No ordering rule.
// - Left child can be greater or smaller than root.
// - Right child can be greater or smaller than root.

// BST (Binary Search Tree):
// - It is a Binary Tree + an ordering rule.
// - Left subtree contains values smaller than root.
// - Right subtree contains values greater than root.
// - Inorder traversal gives values in sorted order.

// Example:
//
// Binary Tree:              BST:
//
//       50                     50
//      /  \                   /  \
//     80   20                30    70
//                            / \    / \
//                           20 40  60 80
//
// In Binary Tree: 80 can be on the left of 50.
// In BST:          80 must be on the right of 50.