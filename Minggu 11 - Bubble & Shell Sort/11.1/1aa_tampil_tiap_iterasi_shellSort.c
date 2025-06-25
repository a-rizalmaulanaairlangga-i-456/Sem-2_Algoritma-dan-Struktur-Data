#include <stdio.h>

// Inisialisasi fungsi sort
void shellSort(int data[], int batas);
// fungsi pendukung tambahan
void tampilkan(int data[], int batas);

// Fungsi utama
int main() {
    int batas = 10;
    int data[10] = {2, 6, 1, 3, 8, 4, 7, 5, 9, 0};

    printf("1.a.a Tampilkan hasil setiap iterasi - Shell Sort:\n");

    printf("\nData sebelum sorting:\n");
    tampilkan(data, batas);

    shellSort(data, batas);

    printf("\nData setelah sorting:\n");
    tampilkan(data, batas);

    return 0;
}

// Implementasi fungsi Shell Sort
void shellSort(int data[], int batas) {
    int jarak = batas;
    int did_swap, i, temp;

    while (jarak > 1) {
        jarak = jarak / 5;
        did_swap = 1;            // set did_swap true untuk mulai loop

        while (did_swap == 1) {
            did_swap = 0;        // reset did_swap setiap iterasi
            i = 0;

            printf("sequence number %d:\n", jarak);
            while (i < (batas - jarak)) {
                if (data[i] > data[i + jarak]) {
                    // Tukar data[i] dan data[i+jarak]
                    temp = data[i];
                    data[i] = data[i + jarak];
                    data[i + jarak] = temp;
                    did_swap = 1;    // set did_swap true jika ada pertukaran
                }
                i = i + 1;
                // tampilkan hasil setiap iterasi
                if (did_swap == 1) {
                    printf("Iterasi ke-%d\n", i);
                    tampilkan(data, batas);
                }
            }
            if (did_swap == 0) printf("Tidak ada penukaran data\n");
            printf("\n");
        }
    }
}

// Implementasi fungsi menampilkan data
void tampilkan(int data[], int batas) {
    for (int i = 0; i < batas; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}
