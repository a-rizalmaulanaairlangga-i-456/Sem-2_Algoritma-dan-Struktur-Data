#include <stdio.h>

// Fungsi insertion sort
void InsertionSort(int array[], int batas) {
    int depan, belakang, key;
    for (depan = 1; depan < batas; depan++) {
        key = array[depan];     // Assign elemen array indeks depan ke key
        belakang = depan - 1;      // Inisialisasi belakang untuk pembandingan
        
        // Bandingkan elemen array pada indeks belakang dengan key
        while (belakang >= 0 && array[belakang] > key) {
            array[belakang + 1] = array[belakang]; // Pindahkan elemen tersebut ke 1 posisi berikutnya
            belakang = belakang - 1;       // Pindah ke elemen sebelumnya
        }
        
        array[belakang + 1] = key;   // Assign key kembali ke array
    }
}

// Fungsi untuk mencetak array
void printArray(int array[], int batas) {
    for (int i = 0; i < batas; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Fungsi utama
int main() {
    int batas;
    printf("Masukkan jumlah elemen array: ");
    scanf("%d", &batas);

    int array[batas];
    printf("Masukkan elemen array:\n");
    for (int i = 0; i < batas; i++) {
        scanf("%d", &array[i]);
    }

    printf("Array sebelum diurutkan: ");
    printArray(array, batas);

    InsertionSort(array, batas);

    printf("Array setelah diurutkan: ");
    printArray(array, batas);

    return 0;
}
