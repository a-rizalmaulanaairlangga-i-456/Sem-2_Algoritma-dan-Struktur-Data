#include <stdio.h>

// Inisialisasi fungsi sort
void shellSort(int data[], int batas);
// fungsi pendukung tambahan
void tampilkan(int data[], int batas);

// Fungsi utama
int main() {
    int batas = 10;
    int data[10] = {2, 6, 1, 3, 8, 4, 7, 5, 9, 0};

    printf("1.a.b Tampilkan hasil setiap iterasi dengan comparison, swapping dan movement - Shell Sort:\n");

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
    int C = 0; // Comparison
    int S = 0; // Swapping
    int M = 0; // Movement

    while (jarak > 1) {
        jarak = jarak / 3;
        did_swap = 1;            // set did_swap true untuk mulai loop

        while (did_swap == 1) {
            did_swap = 0;        // reset did_swap setiap iterasi
            i = 0;

            printf("sequence number %d:\n", jarak);
            while (i < (batas - jarak)) {
                C++;
                if (data[i] > data[i + jarak]) {
                    // Tukar data[i] dan data[i+jarak]
                    temp = data[i];
                    data[i] = data[i + jarak];
                    data[i + jarak] = temp;
                    S++;
                    M += 3;
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
    printf("Total comparison (C) = %d\n", C);
    printf("Total swapping   (S) = %d\n", S);
    printf("Total movement   (M) = %d\n", M);
}

// Implementasi fungsi menampilkan data
void tampilkan(int data[], int batas) {
    for (int i = 0; i < batas; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}
