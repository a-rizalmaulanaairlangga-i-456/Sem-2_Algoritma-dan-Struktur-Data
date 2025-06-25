#include <stdio.h>

// Fungsi Selection Sort
void selectionSort(int array[], int batas) {
    int awal, cari, kecil, temp;

    for (awal = 0; awal < batas - 1; awal++) {
        kecil = awal;           // Inisialisasi dengan indeks awal

        for (cari = awal + 1; cari < batas; cari++) {
            // Bandingkan array didepannya apakah lebih kecil dengan array yang dianggap kecil sebelumnya
            if (array[cari] < array[kecil]) {
                kecil = cari;           // Dapatkan indeks yang dicari ke kecil
            }
        }

        // Tukar array indeks awal dengan array indeks kecil (yang angkanya lebih kecil dari sebelumnya)
        temp = array[awal];
        array[awal] = array[kecil];
        array[kecil] = temp;
    }
}

// Fungsi utama
int main() {
    int batas, i;

    printf("Masukkan jumlah elemen array: ");
    scanf("%d", &batas);

    int array[batas];
    printf("Masukkan elemen array:\n");
    for (i = 0; i < batas; i++) {
        scanf("%d", &array[i]);
    }

    // Panggil fungsi selectionSort
    selectionSort(array, batas);

    // Tampilkan hasil array setelah diurutkan
    printf("Array setelah diurutkan (Selection Sort):\n");
    for (i = 0; i < batas; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
