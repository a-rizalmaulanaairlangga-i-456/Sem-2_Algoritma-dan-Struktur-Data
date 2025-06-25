#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BATAS_MAX 20000

// Deklarasi fungsi
void bubbleSort(int data[], int batas, int ascending);
void shellSort(int data[], int batas, int ascending);
void tampilkan(int data[], int batas);
void generate(int data[], int batas);
int mode_urut();

int main() {
    int batas = BATAS_MAX;
    int data[BATAS_MAX];
    int ascending;
    clock_t start, end;
    double waktu;

    printf("2. Sorting data (Shell sort dan Bubble sort) dengan tes waktu eksekusi:\n\n");

    // Pilih mode urutan
    ascending = mode_urut();

    // Generate data acak
    generate(data, batas);
    printf("Data acak berhasil dibuat.\n");

    // ----- Bubble Sort -----
    int dataBubble[BATAS_MAX];
    for (int i = 0; i < batas; i++) dataBubble[i] = data[i];
    
    printf("\n-- Bubble Sort --\n");
    start = clock();
    bubbleSort(dataBubble, batas, ascending);
    end = clock();
    waktu = (double)(end - start) / CLOCKS_PER_SEC;
    tampilkan(dataBubble, batas);
    printf("Waktu komputasi Bubble Sort: %.4f detik\n", waktu);

    // ----- Shell Sort -----
    int dataShell[BATAS_MAX];
    for (int i = 0; i < batas; i++) dataShell[i] = data[i];

    printf("\n-- Shell Sort --\n");
    start = clock();
    shellSort(dataShell, batas, ascending);
    end = clock();
    waktu = (double)(end - start) / CLOCKS_PER_SEC;
    tampilkan(dataShell, batas);
    printf("Waktu komputasi Shell Sort: %.4f detik\n", waktu);

    return 0;
}

// Fungsi untuk memilih mode urut
int mode_urut() {
    int mode;
    printf("Pilih mode urut:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilihan: ");
    scanf("%d", &mode);
    return (mode == 1) ? 1 : 0;
}

// Fungsi generate bilangan acak
void generate(int data[], int batas) {
    srand(time(NULL));
    for (int i = 0; i < batas; i++) {
        data[i] = rand() % 100000; // Angka acak hingga 100000
    }
}

// Fungsi menampilkan sebagian data
void tampilkan(int data[], int batas) {
    for (int i = 0; i < (batas > 100 ? 100 : batas); i++) {
        printf("%d ", data[i]);
    }
    if (batas > 100) printf("... (total %d elemen)\n", batas);
    else printf("\n");
}

// Bubble Sort dengan hitung C, S, M
void bubbleSort(int data[], int batas, int ascending) {
    int did_swap = 1;
    int i, j, temp;
    long long C = 0, S = 0, M = 0;

    for (i = 0; i < batas && did_swap; i++) {
        did_swap = 0;
        for (j = 0; j < batas - i - 1; j++) {
            C++;
            if ((ascending && data[j] > data[j + 1]) ||
                (!ascending && data[j] < data[j + 1])) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                S++;
                M += 3;
                did_swap = 1;
            }
        }
    }

    printf("Total comparison (C): %lld\n", C);
    printf("Total swapping   (S): %lld\n", S);
    printf("Total movement   (M): %lld\n", M);
}

// Shell Sort dengan hitung C, S, M
void shellSort(int data[], int batas, int ascending) {
    int jarak = batas;
    int did_swap, i, temp;
    long long C = 0, S = 0, M = 0;

    while (jarak > 1) {
        jarak /= 10;
        did_swap = 1;
        while (did_swap) {
            did_swap = 0;
            i = 0;
            while (i < batas - jarak) {
                C++;
                if ((ascending && data[i] > data[i + jarak]) ||
                    (!ascending && data[i] < data[i + jarak])) {
                    temp = data[i];
                    data[i] = data[i + jarak];
                    data[i + jarak] = temp;
                    S++;
                    M += 3;
                    did_swap = 1;
                }
                i++;
            }
        }
    }

    printf("Total comparison (C): %lld\n", C);
    printf("Total swapping   (S): %lld\n", S);
    printf("Total movement   (M): %lld\n", M);
}
