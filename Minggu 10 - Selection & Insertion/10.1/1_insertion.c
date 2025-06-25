#include <stdio.h>

#define batas 10
int array[batas] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, c = 0, s = 0;

// Deklarasi fungsi-fungsi
void InsertionSort();
void tampil();

// Fungsi utama
int main() {
    printf("1. Insertion Sort: \n");

    printf("Array sebelum diurutkan: ");
    tampil();

    InsertionSort();

    printf("Array setelah diurutkan: ");
    tampil();

    return 0;
}

// Fungsi insertion sort
void InsertionSort() {
    int depan, belakang, key;
    for (depan = 1; depan < batas; depan++) {
        key = array[depan];     // Assign elemen array indeks depan ke key untuk disimpan
        belakang = depan - 1;      // Inisialisasi belakang untuk pembandingan
        
        // Bandingkan elemen array pada indeks belakang dengan key (akan terus dibandingkan sampai key>array[belakang])
        while (belakang >= 0 && array[belakang] > key) {
            c++;
            array[belakang + 1] = array[belakang]; // Pindahkan elemen dengan indeks belakang maju 1x ke depan
            belakang--;       // Pindah ke elemen sebelumnya
            s++;
        }
        
        array[belakang + 1] = key;   // Assign key kembali ke array
        s++;
    }
}

// Fungsi untuk menampilkan array
void tampil() {
    for (int i = 0; i < batas; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Jumlah comparison: %d\n", c);
    printf("Jumlah swapping: %d\n\n", s);
}

