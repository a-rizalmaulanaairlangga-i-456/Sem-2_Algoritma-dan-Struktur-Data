#include <stdio.h>

#define MAX 100

// Deklarasi fungsi
void sort_with_quick(int array[], int n);
void quickSort(int array[], int kiri, int kanan);
int partition(int array[], int kiri, int kanan);
void tukar(int *a, int *b);
void tampilkan(int array[], int jumlah);

// Fungsi utama
int main() {
    int data[MAX]; 
    int jumlah = 0;
    sort_with_quick(data, jumlah);
    return 0;
}

// Fungsi Quick Sort
void sort_with_quick(int array[], int n) {
    printf("Jumlah Array: ");
    scanf("%d", &n);

    printf("Isi Array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    quickSort(array, 0, n - 1);

    tampilkan(array, n);
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
    for (int i = 0; i < jumlah; i++) if(array[i] % 2 == 0) printf("%d ", array[i]);
    for (int i = jumlah; i >= 0; i--) if(array[i] % 2 == 1) printf("%d ", array[i]);

    printf("\n");
}
