#include <stdio.h>

#define batas 10
int array[batas] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, c = 0, s = 0;

// Deklarasi fungsi-fungsi
void selectionSort();
void tampil();

// Fungsi utama
int main() {
    printf("2. Selection Sort: \n");

    printf("Array sebelum diurutkan: ");
    tampil();

    selectionSort();

    printf("Array setelah diurutkan: ");
    tampil();


    return 0;
}

// Fungsi Selection Sort
void selectionSort() {
    int awal, cari, kecil, temp;

    for (awal = 0; awal < batas - 1; awal++) {
        kecil = awal;           // Inisialisasi dengan indeks awal

        for (cari = awal + 1; cari < batas; cari++) {
            c++;
            // Bandingkan array didepannya apakah lebih kecil dengan array yang dianggap kecil sebelumnya
            if (array[cari] < array[kecil]) {
                kecil = cari;           // Dapatkan indeks yang dicari ke kecil
            }
        }

        // Tukar array indeks awal dengan array indeks kecil (yang angkanya lebih kecil dari sebelumnya)
        temp = array[awal];
        array[awal] = array[kecil];
        array[kecil] = temp;
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
