#include <stdio.h>

// Inisialisasi fungsi sort
void shellSort(int data[], int batas);
// fungsi pendukung tambahan
void tampilkan(int data[], int batas);
void input_data(int data[], int batas);

// Fungsi utama
int main() {
    int batas;
    printf("Shell Sort:\n");

    printf("Masukkan jumlah data: ");
    scanf("%d", &batas);

    int data[batas];
    input_data(data, batas);

    printf("\nData sebelum sorting:\n");
    tampilkan(data, batas);

    shellSort(data, batas);

    printf("\nData setelah sorting:\n");
    tampilkan(data, batas);

    return 0;
}

// Implementasi fungsi input data
void input_data(int data[], int batas) {
    printf("Masukkan %d elemen:\n", batas);
    for (int i = 0; i < batas; i++) {
        printf("Data ke-%d: ", i + 1);
        scanf("%d", &data[i]);
    }
}

// Implementasi fungsi Shell Sort
void shellSort(int data[], int batas) {
    int jarak = batas;
    int did_swap, i, temp;

    while (jarak > 1) {
        jarak = jarak / 2;
        did_swap = 1;            // set did_swap true untuk mulai loop

        while (did_swap == 1) {
            did_swap = 0;        // reset did_swap setiap iterasi
            i = 0;

            while (i < (batas - jarak)) {
                if (data[i] > data[i + jarak]) {
                    // Tukar data[i] dan data[i+jarak]
                    temp = data[i];
                    data[i] = data[i + jarak];
                    data[i + jarak] = temp;
                    did_swap = 1;    // set did_swap true jika ada pertukaran
                }
                i = i + 1;
            }
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
