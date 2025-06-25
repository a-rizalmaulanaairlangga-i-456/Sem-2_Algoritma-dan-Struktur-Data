#include "sort.h"



void do_quick_sort(int arr[], int n) {

    quick_sort(arr, 0, n - 1);

}

void quick_sort (int arr[], int leftIdk, int rightIdk) {

    if (leftIdk < rightIdk) {

        int pivotIdk = partition(arr, leftIdk, rightIdk);

        quick_sort(arr, leftIdk, pivotIdk - 1);
        quick_sort(arr, pivotIdk + 1, rightIdk);

    }

}

int partition(int arr[], int leftIdk, int rightIdk) {

    int pivot = arr[get_pivot_index(leftIdk, rightIdk, LAST_ELEMENT)];

    int i = leftIdk - 1, j = leftIdk;

    for(; j < rightIdk; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[rightIdk]);

    return ++i;

}

int get_pivot_index(int leftIdk, int rightIdk, PivotStrategy pivotStrategy) {
    switch (pivotStrategy)
    {
    case FIRST_ELEMENT:
        /* code */
        return leftIdk;
        break;
    case LAST_ELEMENT:
        return rightIdk;
        break;
    default:
        return 0;
        break;
    }
}

void swap (int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

