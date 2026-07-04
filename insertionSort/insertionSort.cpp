//
// Created by NITHIN SAI on 03-07-2026.
//

#include "insertionSort.h"
#include <iostream>

using namespace std;

void insertionSort(int arr[],int n) {
    for (int i=0;i<n;i++) {
        int j = i;
        while (j>0 && arr[j-1] > arr[j]) {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }

    for (int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
}

int main() {

    int arr[] = {8,9,1,2};
    int n = 4;
    insertionSort(arr,n);

    return 0;
}
