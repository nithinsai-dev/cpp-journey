//
// Created by NITHIN SAI on 03-07-2026.
//

#include "SelectionSort.h"
#include <iostream>

using namespace std;

void selectionSort(int arr[],int n) {
    for (int i=0;i<n-2;i++) {
        int minIndex = i;
        for (int j=i+1;j<n-1;j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
    for (int i=0;i<n-1;i++) {
        cout << arr[i] << " ";
    }
}

int main() {

    int arr[] = {8,9,1,2};
    int n = 4;
    selectionSort(arr,n);

    return 0;
}