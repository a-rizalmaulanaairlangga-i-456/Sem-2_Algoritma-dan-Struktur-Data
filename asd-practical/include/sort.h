#ifndef SORT_H
#define SORT_H

typedef enum {
    FIRST_ELEMENT,
    LAST_ELEMENT,
    MIDDLE_ELEMENT,
    MEDIAN_OF_THREE,
    RANDOM_PIVOT
} PivotStrategy;

void do_selection_sort(int arr[], int n);
void do_insertion_sort(int arr[], int gap, int n);
void do_bubble_sort(int arr[], int gap, int n);
void do_shell_sort(int arr[], int n, int gap[], int nGap);

// Merge Sort
void do_merge_sort(int arr[], int n);
void divide(int arr[], int leftIdk, int rightIdk);
void conquer(int arr[], int leftIdk, int midIdk, int rightIdk);

// Quick Sort
void do_quick_sort(int arr[], int n);
void quick_sort(int arr[], int leftIdk, int rightIdk);
int partition(int arr[], int leftIdk, int rightIdk);
void swap (int *num1, int *num2);
int get_pivot_index(int leftIdk, int rightIdk, PivotStrategy pivotStrategy);

#endif