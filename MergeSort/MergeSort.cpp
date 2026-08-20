//
// Created by NITHIN SAI on 04-07-2026.
//

#include "MergeSort.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void mergeSort(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);

    //merge
    int left = low, right = mid+1;
    vector<int> v;
    while (left <=mid && right <=high) {
        if (arr[left] < arr[right]) {
            v.push_back(arr[left]);
            left++;
        } else {
            v.push_back(arr[right]);
            right++;
        }
    }
    while (left <=mid) {
        v.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        v.push_back(arr[right]);
        right++;
    }

    for (int i=low;i<=high;i++) {
        arr[i] = v[i-low];
    }
}

int main() {

    int arr1[] = {8,9,1,2,5,3,7,9,1,3,6,7,4,9,7,4,1};
    int n =sizeof(arr1)/sizeof(arr1[0]);
    mergeSort(arr1,0,n-1);
    for (int i=0;i<n;i++) {
        cout<<arr1[i]<<" ";
    }

    return 0;
}

Node* merge(Node*left,Node* right) {
    Node dummy;
    Node* tail = &dummy;

    dummy.next=nullptr;
    while (left!=nullptr&&right!=nullptr) {
        if (left->data<right->data) {
            tail->next = left;
        } else {
            tail->next = right;
        }
        tail = tail-> next;
    }
    if (left!=nullptr) {
        tail->next = left;
    }else {
        tail->next = right;
    }
    return dummy.next;
}
Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* slow=head;
    Node* fast=  head;
    Node* prev = nullptr;

    while (fast != nullptr && fast->next!=nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = nullptr;

    Node* left = mergeSort(head);
    Node* right = mergeSort(slow);
    return merge(left,right);
}