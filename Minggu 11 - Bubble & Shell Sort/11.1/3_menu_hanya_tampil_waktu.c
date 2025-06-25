#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BATAS_MAX 20000

// Deklarasi fungsi
void bubbleSort(int data[], int batas, int ascending);
void shellSort(int data[], int batas, int ascending);
void insertionSort(int data[], int batas, int ascending);
void selectionSort(int data[], int batas, int ascending);
void generate(int data[], int batas);
int mode_urut();
void pilih_sort(int data[]);
double hitung_waktu(int data[], int batas, int ascending, int metode);

// Main
int main() {
    int data[BATAS_MAX];

    printf("3. Menu pilihan sorting (Bubble sort, Selection sort, Insertion sort dan Selection sort) dengan metode urut (asc atau dsc) untuk menampilkan waktu eksekusi:\n");

    pilih_sort(data);

    return 0;
}

// Fungsi memilih metode sorting
void pilih_sort(int data[]) {
    int batas = BATAS_MAX;
    int ascending;
    int metode;
    double hasil_waktu;

    while (1) {
        printf("Pilih metode sorting:\n");
        printf("1. Bubble Sort\n");
        printf("2. Shell Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Selection Sort\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &metode);
        
        if (metode == 5) exit(0);
        // Pilih mode urutan
        ascending = mode_urut();
        // Generate data acak
        generate(data, batas);
    
        // Duplikasi array sebelum sorting
        int dataSort[BATAS_MAX];
        for (int i = 0; i < batas; i++) dataSort[i] = data[i];
    
        // Eksekusi dan ukur waktu
        hasil_waktu = hitung_waktu(dataSort, batas, ascending, metode);
        printf("Waktu komputasi: %f detik\n\n", hasil_waktu);
    }
    return;
}

// Fungsi memilih mode urut
int mode_urut() {
    int mode;
    printf("Pilih mode urut:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilihan: ");
    scanf("%d", &mode);
    return (mode == 1) ? 1 : 0;
}

// Fungsi generate data acak
void generate(int data[], int batas) {
    srand(time(NULL));
    for (int i = 0; i < batas; i++) {
        data[i] = rand() % 100000;
    }
}

// Fungsi Bubble Sort
void bubbleSort(int data[], int batas, int ascending) {
    int temp, did_swap = 1;
    for (int i = 0; i < batas && did_swap; i++) {
        did_swap = 0;
        for (int j = 0; j < batas - i - 1; j++) {
            if ((ascending && data[j] > data[j + 1]) ||
                (!ascending && data[j] < data[j + 1])) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                did_swap = 1;
            }
        }
    }
}

// Fungsi Shell Sort
void shellSort(int data[], int batas, int ascending) {
    int jarak = batas, temp;
    while (jarak > 1) {
        jarak /= 10;
        for (int i = jarak; i < batas; i++) {
            int j = i;
            while (j >= jarak &&
                ((ascending && data[j - jarak] > data[j]) ||
                 (!ascending && data[j - jarak] < data[j]))) {
                temp = data[j];
                data[j] = data[j - jarak];
                data[j - jarak] = temp;
                j -= jarak;
            }
        }
    }
}

// Fungsi Insertion Sort
void insertionSort(int data[], int batas, int ascending) {
    int key, j;
    for (int i = 1; i < batas; i++) {
        key = data[i];
        j = i - 1;
        while (j >= 0 &&
              ((ascending && data[j] > key) ||
               (!ascending && data[j] < key))) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

// Fungsi Selection Sort
void selectionSort(int data[], int batas, int ascending) {
    int i, j, idx, temp;
    for (i = 0; i < batas - 1; i++) {
        idx = i;
        for (j = i + 1; j < batas; j++) {
            if ((ascending && data[j] < data[idx]) ||
                (!ascending && data[j] > data[idx])) {
                idx = j;
            }
        }
        if (idx != i) {
            temp = data[i];
            data[i] = data[idx];
            data[idx] = temp;
        }
    }
}

double hitung_waktu(int data[], int batas, int ascending, int metode) {
    clock_t start, end;
    double waktu;

    start = clock();
    switch (metode) {
        case 1: bubbleSort(data, batas, ascending); break;
        case 2: shellSort(data, batas, ascending); break;
        case 3: insertionSort(data, batas, ascending); break;
        case 4: selectionSort(data, batas, ascending); break;
        default: printf("Metode tidak valid!\n"); return 1;
    }
    end = clock();
    waktu = (double)(end - start) / CLOCKS_PER_SEC;
    return waktu;
}