#include "sort.h"

/**
 * Mengurutkan array dengan metode Bubble Sort.
 * @param gap Jarak antar elemen yang dibandingkan; biasanya 1 untuk Bubble Sort biasa.
 * @details Jika digunakan untuk Shell Sort, sesuaikan nilai gap dan pastikan iterasi terakhir menggunakan gap = 1.
 */

void do_bubble_sort(int arr[], int gap, int n) {
    int swapped;

    do{

        swapped = 0;

        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i+gap]) {
                int temp = arr[i];
                arr[i] = arr[i+gap];
                arr[i+gap] = temp;

                swapped = 1;            
            }
        }

    } while (swapped);
}