#include <stdio.h>
#include "sort.h"

// Insertion Sort
void pengurutan_insertion(int data[], int jarak, int jumlah){
    for (int indeks_data = jarak; indeks_data < jumlah; indeks_data++) {
        int data_sisip = data[indeks_data];
        int posisi = indeks_data;
        while (posisi >= jarak && data[posisi - jarak] > data_sisip) {
            data[posisi] = data[posisi - jarak];
            posisi -= jarak;
        }
        data[posisi] = data_sisip;
    }
}

// Selection Sort
void pengurutan_selection(int data[], int jumlah){
    for (int i = 0; i < jumlah - 1; i++) {
        int indeks_terkecil = i;
        for(int j = i + 1; j < jumlah; j++) {
            if(data[indeks_terkecil] > data[j]) {
                indeks_terkecil = j;
            }
        }
        if (indeks_terkecil != i) {
            int sementara = data[i];
            data[i] = data[indeks_terkecil];
            data[indeks_terkecil] = sementara;
        }
    }   
}

// Bubble Sort
void pengurutan_bubble(int data[], int jarak, int jumlah) {
    int ditukar;
    do{
        ditukar = 0;
        for (int i = 0; i + jarak < jumlah; i++) {
            if (data[i] > data[i+jarak]) {
                int sementara = data[i];
                data[i] = data[i+jarak];
                data[i+jarak] = sementara;
                ditukar = 1;            
            }
        }
    } while (ditukar);
}

// Shell Sort
void pengurutan_shell(int data[], int jumlah, int jarak[], int jumlah_jarak) {
    for (int indeks_jarak = 0; indeks_jarak < jumlah_jarak; indeks_jarak++){
        pengurutan_bubble(data, jarak[indeks_jarak], jumlah);
    }
}

// Merge Sort
void pengurutan_merge(int data[], int jumlah) {
    pembagi_merge(data, 0, jumlah - 1);
}

void pembagi_merge(int data[], int kiri, int kanan){
    if (kiri < kanan) {
        int tengah = (kiri + kanan) / 2;
        pembagi_merge(data, kiri, tengah);
        pembagi_merge(data, tengah + 1, kanan);
        penggabung_merge(data, kiri, tengah, kanan);
    }
}

void penggabung_merge(int data[], int kiri, int tengah, int kanan){
    int hasil[ELEMEN_MAKS];
    int kiri1 = kiri, kanan1 = tengah;
    int kiri2 = tengah + 1, kanan2 = kanan;
    int i = kiri;

    while (kiri1 <= kanan1 && kiri2 <= kanan2) {
        if (data[kiri1] <= data[kiri2]) {
            hasil[i] = data[kiri1];
            kiri1++;
        } else {
            hasil[i] = data[kiri2];
            kiri2++;
        }
        i++;
    }
    while (kiri1 <= kanan1) {
        hasil[i++] = data[kiri1++];
    }
    while (kiri2 <= kanan2) {
        hasil[i++] = data[kiri2++];
    }
    for (int j = kiri; j <= kanan; j++) {
        data[j] = hasil[j];
    }
}

// Quick Sort
void pengurutan_quick(int data[], int jumlah) {
    quick_sort(data, 0, jumlah - 1);
}

void quick_sort (int data[], int kiri, int kanan) {
    if (kiri < kanan) {
        int pivot = partition(data, kiri, kanan);
        quick_sort(data, kiri, pivot - 1);
        quick_sort(data, pivot + 1, kanan);
    }
}

int partition(int data[], int kiri, int kanan) {
    int pivot = data[indeks_pivot(kiri, kanan)];
    int i = kiri - 1;
    for(int j = kiri; j < kanan; j++) {
        if (data[j] <= pivot) {
            i++;
            tukar(&data[i], &data[j]);
        }
    }
    tukar(&data[i+1], &data[kanan]);
    return i+1;
}

int indeks_pivot(int kiri, int kanan) {
    return kanan; // strategi pivot terakhir
}

void tukar (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
