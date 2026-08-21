//
// Created by NITHIN SAI on 21-08-2026.
//

#include "BSTp.h"
#include <iostream>
#include <climits>
using namespace std;

// ======================================================
// TREE NODE
// ======================================================

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


// ======================================================
// BINARY SEARCH TREE
// ======================================================

class BST {
public:

    // --------------------------------------------------
    // INSERT
    // In BST:
    // smaller values -> left
    // larger values  -> right
    // --------------------------------------------------

    TreeNode* insert(TreeNode* root, int val) {

        if (root == nullptr)
            return new TreeNode(val);

        if (val < root->data)
            root->left = insert(root->left, val);

        else if (val > root->data)
            root->right = insert(root->right, val);

        return root;
    }


    // --------------------------------------------------
    // SEARCH
    // Uses BST property to eliminate half of the tree
    // --------------------------------------------------

    bool search(TreeNode* root, int val) {

        if (root == nullptr)
            return false;

        if (root->data == val)
            return true;

        if (val < root->data)
            return search(root->left, val);

        return search(root->right, val);
    }


    // --------------------------------------------------
    // INORDER
    // BST inorder traversal gives sorted order
    // --------------------------------------------------

    void inorder(TreeNode* root) {

        if (root == nullptr)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }


    // --------------------------------------------------
    // PREORDER
    // Root -> Left -> Right
    // --------------------------------------------------

    void preorder(TreeNode* root) {

        if (root == nullptr)
            return;

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }


    // --------------------------------------------------
    // POSTORDER
    // Left -> Right -> Root
    // --------------------------------------------------

    void postorder(TreeNode* root) {

        if (root == nullptr)
            return;

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }


    // --------------------------------------------------
    // FIND MINIMUM
    // Minimum value is the leftmost node
    // --------------------------------------------------

    TreeNode* findMin(TreeNode* root) {

        if (root == nullptr)
            return nullptr;

        while (root->left != nullptr)
            root = root->left;

        return root;
    }


    // --------------------------------------------------
    // FIND MAXIMUM
    // Maximum value is the rightmost node
    // --------------------------------------------------

    TreeNode* findMax(TreeNode* root) {

        if (root == nullptr)
            return nullptr;

        while (root->right != nullptr)
            root = root->right;

        return root;
    }


    // --------------------------------------------------
    // DELETE
    //
    // Three cases:
    // 1. Leaf node
    // 2. Node with one child
    // 3. Node with two children
    // --------------------------------------------------

    TreeNode* deleteNode(TreeNode* root, int val) {

        if (root == nullptr)
            return nullptr;

        // Search in left subtree
        if (val < root->data) {

            root->left = deleteNode(root->left, val);
        }

        // Search in right subtree
        else if (val > root->data) {

            root->right = deleteNode(root->right, val);
        }

        // Node found
        else {

            // Case 1:
            // No left child
            // Can also be a leaf node
            if (root->left == nullptr) {

                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 2:
            // No right child
            if (root->right == nullptr) {

                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3:
            // Two children
            //
            // Find smallest node in right subtree
            TreeNode* temp = findMin(root->right);

            // Replace current node's value
            root->data = temp->data;

            // Delete duplicate value
            root->right = deleteNode(root->right, temp->data);
        }

        return root;
    }


    // --------------------------------------------------
    // INORDER SUCCESSOR
    //
    // Finds the smallest value greater than 'val'
    // --------------------------------------------------

    TreeNode* inorderSuccessor(TreeNode* root, int val) {

        TreeNode* successor =nullptr;

        while (root != nullptr) {

            if (val < root->data) {

                successor = root;
                root = root->left;
            }
            else {

                root = root->right;
            }
        }

        return successor;
    }


    // --------------------------------------------------
    // LCA - LOWEST COMMON ANCESTOR
    //
    // Uses BST property:
    //
    // Both smaller -> go left
    // Both larger  -> go right
    // Otherwise current node is LCA
    // --------------------------------------------------

    TreeNode* LCA(TreeNode* root, int a, int b) {

        if (root == nullptr)
            return nullptr;

        if (a < root->data && b < root->data)
            return LCA(root->left, a, b);

        if (a > root->data && b > root->data)
            return LCA(root->right, a, b);

        return root;
    }


    // --------------------------------------------------
    // CHECK WHETHER A TREE IS A BST
    //
    // Every node must stay within its valid range.
    // --------------------------------------------------

    bool isBST(TreeNode* root, long long minVal, long long maxVal) {

        if (root == nullptr)
            return true;

        if (root->data <= minVal || root->data >= maxVal)
            return false;

        return isBST(root->left, minVal, root->data) &&
               isBST(root->right, root->data, maxVal);
    }
};


// ======================================================
// MAIN
// ======================================================

int main() {

    BST tree;

    TreeNode* root = nullptr;


    // --------------------------------------------------
    // INSERT VALUES
    // --------------------------------------------------

    root = tree.insert(root, 50);
    root = tree.insert(root, 30);
    root = tree.insert(root, 70);
    root = tree.insert(root, 20);
    root = tree.insert(root, 40);
    root = tree.insert(root, 60);
    root = tree.insert(root, 80);


    /*

              50
             /  \
           30    70
          / \    / \
        20  40  60  80

    */


    // --------------------------------------------------
    // TRAVERSALS
    // --------------------------------------------------

    cout << "Inorder: ";
    tree.inorder(root);
    cout << endl;

    cout << "Preorder: ";
    tree.preorder(root);
    cout << endl;

    cout << "Postorder: ";
    tree.postorder(root);
    cout << endl;


    // --------------------------------------------------
    // SEARCH
    // --------------------------------------------------

    int value = 40;

    if (tree.search(root, value))
        cout << value << " found" << endl;
    else
        cout << value << " not found" << endl;


    // --------------------------------------------------
    // MINIMUM
    // --------------------------------------------------

    TreeNode* minNode = tree.findMin(root);

    if (minNode != nullptr)
        cout << "Minimum: " << minNode->data << endl;


    // --------------------------------------------------
    // MAXIMUM
    // --------------------------------------------------

    TreeNode* maxNode = tree.findMax(root);

    if (maxNode != nullptr)
        cout << "Maximum: " << maxNode->data << endl;


    // --------------------------------------------------
    // INORDER SUCCESSOR
    // --------------------------------------------------

    TreeNode* successor = tree.inorderSuccessor(root, 40);

    if (successor != nullptr)
        cout << "Successor of 40: "
             << successor->data << endl;
    else
        cout << "No successor" << endl;


    // --------------------------------------------------
    // LCA
    // --------------------------------------------------

    TreeNode* lca = tree.LCA(root, 20, 40);

    if (lca != nullptr)
        cout << "LCA of 20 and 40: "
             << lca->data << endl;


    // --------------------------------------------------
    // CHECK BST
    // --------------------------------------------------

    if (tree.isBST(root, LLONG_MIN, LLONG_MAX))
        cout << "Tree is a BST" << endl;
    else
        cout << "Tree is not a BST" << endl;


    // --------------------------------------------------
    // DELETE
    // --------------------------------------------------

    cout << "\nBefore deletion: ";
    tree.inorder(root);
    cout << endl;

    root = tree.deleteNode(root, 20);

    cout << "After deleting 20: ";
    tree.inorder(root);
    cout << endl;


    root = tree.deleteNode(root, 30);

    cout << "After deleting 30: ";
    tree.inorder(root);
    cout << endl;


    root = tree.deleteNode(root, 50);

    cout << "After deleting 50: ";
    tree.inorder(root);
    cout << endl;


    return 0;
}
