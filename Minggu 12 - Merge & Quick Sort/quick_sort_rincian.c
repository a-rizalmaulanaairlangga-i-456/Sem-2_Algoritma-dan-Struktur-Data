#include <stdio.h>

#define MAX 100

// Data yang akan diurutkan (bisa juga input manual)
int data[10] = {7, 2, 5, 9, 1, 6, 8, 4, 3, 0};
int n = 10;

// Deklarasi fungsi
void quickSort(int array[], int left, int right, int depth);
int partition(int array[], int left, int right);
void tampilkan(int array[], int n);
void inputManual(int array[], int *n);

int main() {
    // Pilih apakah ingin menggunakan data bawaan atau input manual
    // inputManual(data, &n);

    printf("Data sebelum diurutkan:\n");
    tampilkan(data, n);

    printf("\nMulai proses Quick Sort:\n");
    quickSort(data, 0, n - 1, 0);

    printf("\nData setelah diurutkan (Quick Sort):\n");
    tampilkan(data, n);

    return 0;
}

// Fungsi Quick Sort Rekursif
void quickSort(int array[], int left, int right, int depth) {
    // Indentasi visual berdasarkan kedalaman rekursi
    for (int i = 0; i < depth; i++) printf("  ");
    printf("QuickSort(left = %d, right = %d)\n", left, right);

    if (left < right) {
        int pivotIndex = partition(array, left, right);

        for (int i = 0; i < depth; i++) printf("  ");
        printf("  -> Pivot di indeks %d, nilai = %d\n", pivotIndex, array[pivotIndex]);

        // Rekursi ke bagian kiri
        quickSort(array, left, pivotIndex, depth + 1);
        // Rekursi ke bagian kanan
        quickSort(array, pivotIndex + 1, right, depth + 1);
    }
}

// Fungsi Partition (metode Hoare)
int partition(int array[], int left, int right) {
    int pivot = array[left];  // Pivot adalah elemen pertama
    int i = left;
    int j = right;

    printf("  Partition (left = %d, right = %d, pivot = %d)\n", left, right, pivot);

    while (1) {
        while (array[j] > pivot) j--;
        while (array[i] < pivot) i++;

        if (i < j) {
            printf("    Swap: array[%d] = %d <-> array[%d] = %d\n", i, array[i], j, array[j]);
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        } else {
            return j;
        }
    }
}

// Fungsi untuk menampilkan isi array
void tampilkan(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Fungsi input manual (opsional)
void inputManual(int array[], int *n) {
    printf("Masukkan jumlah elemen: ");
    scanf("%d", n);

    printf("Masukkan %d elemen:\n", *n);
    for (int i = 0; i < *n; i++) {
        printf("Data[%d] = ", i);
        scanf("%d", &array[i]);
    }
}
