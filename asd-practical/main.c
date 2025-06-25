#include <stdio.h>
#include "utils.h"
#include "sort.h"

int main(){
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    // int arr[] = {253, 407, 790, 469, 828, 945, 484, 383, 997, 676, 186};

    /**
     * sizeof() mengeluarkan nilai dalam bentuk byte.
     * Type int berukuran 4 byte / digit
     */

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Nilai data sebelum diurutkan: \n");
    print_array_int_1d(arr, n);    

    // int k[] = {5, 3, 1};
    // int nK = sizeof(k) / sizeof(k[0]);

    printf("Proses Pengurutan: \n");
    do_quick_sort(arr, n);

    printf("Nilai data Setelah diurutkan: \n");
    print_array_int_1d(arr, n);    


    return 0;
}