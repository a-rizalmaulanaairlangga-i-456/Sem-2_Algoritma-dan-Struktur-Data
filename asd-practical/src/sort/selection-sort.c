#include "sort.h"

void do_selection_sort(int arr[], int n){

    for (int i = 0; i < n - 1; i++) {

        int idkSmallestValue = i;

        for(int j = i + 1; j < n; j++) {
            if(arr[idkSmallestValue] > arr[j]) {
                idkSmallestValue = j;
            }
        }

        // Do Swap
        if (idkSmallestValue != i) {
            int temp = arr[i];
            arr[i] = arr[idkSmallestValue];
            arr[idkSmallestValue] = temp;
        }
    }   

}