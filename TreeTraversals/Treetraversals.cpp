//
// Created by NITHIN SAI on 11-08-2026.
//

#include "Treetraversals.h"
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

void preorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void inorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->val  <<  " ";
    inorder(root->right);
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void levelOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << current->val << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right!=nullptr) {
            q.push(current->right);
        }
    }
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(7);

    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);

    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);

    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    levelOrder(root);

    deleteTree(root);
    return 0;
}