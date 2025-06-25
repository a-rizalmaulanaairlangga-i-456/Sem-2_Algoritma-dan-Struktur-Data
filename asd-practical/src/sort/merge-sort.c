#include "sort.h"
#include "utils.h"
#include <stdio.h>

void do_merge_sort(int arr[], int n) {

    divide(arr, 0, n - 1);
    
}

void divide(int arr[], int leftIdk, int rightIdk){

    if (leftIdk < rightIdk) {
        int midIdk = (leftIdk + rightIdk) / 2;

        
        divide(arr, leftIdk, midIdk);  // Left side
        divide(arr, midIdk + 1, rightIdk); // Right side

        conquer(arr, leftIdk, midIdk, rightIdk);
    }

}

void conquer(int arr[], int leftIdk, int midIdk, int rightIdk){

    int n1 = midIdk - leftIdk + 1;
    int n2 = rightIdk - midIdk;

    int L[n1], R[n2]; // Define partition

    // Assign value from original array to partition array
    for (int i = 0; i < n1; i++) {
        L[i] = arr[leftIdk + i];
    }

    for (int i = 0; i < n2; i++) {
        R[i] = arr[midIdk + i + 1];
    }

    int i = 0, j = 0, k = leftIdk;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Make sure that no data left
    while (i < n1) {
        arr[k++] = L[i++];
    }

    while(j < n2) {
        arr[k++] = R[j++];
    }

}