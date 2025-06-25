#include <stdio.h>

#define MAX 100

// Deklarasi fungsi
void quickSort(int array[], int kiri, int kanan);
int partition(int array[], int kiri, int kanan);
void tukar(int *a, int *b);
void tampilkan(int array[], int jumlah);
void inputManual(int array[], int *jumlah);

// Fungsi utama
int main() {
    int data[MAX] = {8, 3, 7, 4, 9, 2, 6, 5, 1, 0}; // Data awal
    int jumlah = 10;

    // Untuk input manual, uncomment baris berikut:
    // inputManual(data, &jumlah);

    printf("Data sebelum sorting:\n");
    tampilkan(data, jumlah);

    quickSort(data, 0, jumlah - 1);

    printf("Data setelah Quick Sort:\n");
    tampilkan(data, jumlah);

    return 0;
}

// Fungsi Quick Sort
void quickSort(int array[], int kiri, int kanan) {
    if (kiri < kanan) {
        int indexPivot = partition(array, kiri, kanan);
        quickSort(array, kiri, indexPivot);       // kiri sampai sebelum pivot
        quickSort(array, indexPivot + 1, kanan);  // setelah pivot sampai kanan
    }
}

// Fungsi Partition (Skema Hoare)
int partition(int array[], int kiri, int kanan) {
    int pivot = array[kiri];
    int i = kiri;
    int j = kanan;

    while (1) {
        while (array[j] > pivot) j--;
        while (array[i] < pivot) i++;

        if (i < j) {
            tukar(&array[i], &array[j]);
            i++;
            j--;
        } else {
            return j;
        }
    }
}

// Fungsi untuk menukar dua nilai
void tukar(int *a, int *b) {
    int sementara = *a;
    *a = *b;
    *b = sementara;
}

// Fungsi menampilkan isi array
void tampilkan(int array[], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Fungsi untuk input manual
void inputManual(int array[], int *jumlah) {
    printf("Masukkan jumlah elemen: ");
    scanf("%d", jumlah);

    for (int i = 0; i < *jumlah; i++) {
        printf("Data[%d]: ", i);
        scanf("%d", &array[i]);
    }
}
