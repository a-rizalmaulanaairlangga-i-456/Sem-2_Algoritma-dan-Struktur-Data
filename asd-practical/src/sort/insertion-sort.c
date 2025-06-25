#include "sort.h"

/**
 * Mengurutkan array dengan metode Insertion Sort.
 * @param gap Jarak antar elemen yang dibandingkan; biasanya 1 untuk Insertion Sort biasa.
 * @details Jika digunakan untuk Shell Sort, sesuaikan nilai gap dan pastikan iterasi terakhir menggunakan gap = 1.
 */

void do_insertion_sort(int arr[], int gap, int n){

    for (int i = gap; i < n; i++) {

        int key = arr[i];
        int j = i;

        while(j >= gap && arr[j - gap ] > key) {
            arr[j] = arr[j - gap];
            j-=gap; 
        }

        arr[j] = key;

    }

}