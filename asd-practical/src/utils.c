#include <stdio.h>
#include "utils.h"

int get_random_number(int n) {
    return 0;
}

void print_array_int_1d(int arr[], int n)
{
    for (int i = 0; i < n; i++){ 
        printf("%d", arr[i]);

        if (i < (n - 1)) printf(", ");
    }

    printf("\n");
}