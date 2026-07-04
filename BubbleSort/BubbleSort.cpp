//
// Created by NITHIN SAI on 03-07-2026.
//

#include "BubbleSort.h"
#include <iostream>

using namespace std;

void bubbleSort(int arr[],int n) {
    for (int i=0;i<n-1;i++) {
        // int didSwap = 0;
        for (int j=0;j<n-i-1;j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                //didSwap = 1;
            }
        }
        //if (didSwap == 0){
        //      break;
        //}   -> optimize the bubble sort more efficient.
    }
    for (int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
}

int main() {

    int arr[] = {8,9,1,2};
    int n = 4;
    bubbleSort(arr,n);

    return 0;
}
