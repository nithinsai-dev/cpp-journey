//
// Created by NITHIN SAI on 18-08-2026.
//

#include "solution.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value),left(nullptr),right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    int height(TreeNode* node) {
        if (node==nullptr) {
            return -1;
        }
        return max(height(node->left),height(node->right))+1;
    }

    TreeNode* findNode(TreeNode* current,int value) {
        if (current == nullptr) {
            return nullptr;
        }
        if (current -> data == value) {
            return current;
        }

        TreeNode* leftSearch = findNode(current->left,value);
        if (leftSearch == nullptr) {
            return nullptr;
        }
        return findNode(current->right,value);
    }

    bool findPath(TreeNode* current,int value,vector<int>& path) {
        if (current==nullptr) {
            return false;
        }
        path.push_back(current->data);
        if (current->data == value) {
            return true;
        }

        if (findPath(current->left,value,path)) {
            return true;
        }
        if (findPath(current->right,value,path)) {
            return true;
        }
        path.pop_back();
        return false;
    }
    bool findProper(TreeNode* current) {
        if (current == nullptr) {
            return true;
        }

        //exactly one child
        if ((current->left == nullptr&&current->right!=nullptr)||(current->left!=nullptr&&current->right==nullptr)) {
            return false;
        }
        return findProper(current->left)&&findProper(current->right);
    }
    int findDepth(TreeNode* current,int value,int depth) {
        if (current == nullptr) {
            return -1;
        }
        if (current->data == value) {
            return depth;
        }
        int leftResult = findDepth(current->left,value,depth+1);
        if (leftResult != -1) {
            return leftResult;
        }
        return findDepth(current->right,value,depth+1);
    }

public:
    BinaryTree() : root(nullptr) {}

    void buildTree(vector<int>& arr) {
        vector<TreeNode*> nodes(arr.size(),nullptr);

        for (int i=1;i<arr.size();i++) {
            nodes[i] = new TreeNode(arr[i]);
        }

        for (int i=0;i<nodes.size();i++) {
            int left = 2*i;
            int right=2*i+1;

            if (left<arr.size()) {
                nodes[i] -> left = nodes[left];
            } if (right < arr.size()) {
                nodes[i] -> right = nodes[right];
            }
        }

        root  = nodes[1];
    }

    bool addChild(int U,int V) {
        TreeNode* parent = findNode(root,U);
        if (parent == nullptr) {
            return false;
        }
        TreeNode* child = new TreeNode(V);

        if (parent->left == nullptr) {
            parent->left = child;
            return true;
        } else if (parent->right) {
            parent->right = child;
            return true;
        }

        delete child;
        return false;
    }

    int findHeight(int V) {
        TreeNode* current = findNode(root,V);
        if (current == nullptr) {
            return -1;
        }
        return height(current);
    }

    bool findComplete(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        vector<TreeNode*> q;
        q.push_back(root);

        int front=0;
        bool foundNull=false;

        while (front < q.size()) {
            TreeNode* current = q[front];

            if (current == nullptr) {
                foundNull=true;
                continue;
            }
            if (foundNull) {
                return false;
            }
            q.push_back(current->left);
            q.push_back(current->right);
            front++;
        }
    }

    int findCommonAncestors(int v1,int v2) {
        vector<int> path1;
        vector<int> path2;

        if (!findPath(root,v1,path1)) {
            return -1;
        }
        if (!findPath(root,v2,path2)) {
            return -1;
        }
        int answer=-1;
        int i=0;
        while (i<path1.size() && i<path2.size() && path1[i] == path2[i]) {
            answer = path1[i];
            i++;
        }
        return answer;
    }

    int distanceBetween(int v1,int v2) {
        vector<int> path1;
        vector<int> path2;

        if (!findPath(root,v1,path1)) {
            return -1;
        }
        if (!findPath(root,v2,path2)) {
            return -1;
        }
        int answer=-1;
        int i=0;
        while (i<path1.size() && i<path2.size() && path1[i] == path2[i]) {
            answer = path1[i];
            i++;
        }
        int d1=path1.size()-i;
        int d2=path2.size()-i;
        return d1+d2;
    }

    bool findCousins(int v1,int v2) {
        vector<int> path1;
        vector<int> path2;

        if (!findPath(root,v1,path1)) {
            return false;
        }
        if (!findPath(root,v2,path2)) {
            return false;
        }
        if (path1.size() < 2||path2.size() < 2) {
            return false;
        }
        if (path1.size()!=path2.size()) {
            return false;
        }
        if (path1[path1.size()-2]==path2[path2.size()-2]) {
            return false;
        }
        return true;
    }
    bool findProperTree() {
        return findProper(root);
    }

    int findDepth(int value) {
        return findDepth(root,value,0);
    }
};

int main() {
    return 0;
}
