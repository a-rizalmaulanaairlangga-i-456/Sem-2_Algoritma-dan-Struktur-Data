#include "sort.h"
#include "utils.h"
#include <stdio.h>

void do_shell_sort(int arr[], int n, int gap[], int nGap) {

    /**
     * Shell-Bubble: Versi Asli 1960
     * Shell-Insertion: Versi Modern & Teks Book (Lebih Efisien)
     */
    
    int iGap = 0;
    while (iGap < nGap){

        /** Do Bubble Sort with K Value */
        do_bubble_sort(arr, gap[iGap], n);
        // do_insertion_sort(arr, gap[iGap], n);

        iGap++;
    }

}