#include <stdio.h>

// deklarasi fungint data[], int batassi sort
void bubbleSort(int data[], int batas);
    // fungsi pendukung tambahan
void tampilkan(int data[], int batas);


// fungsi utama
int main() {
    int batas = 10;
    int data[10] = {2, 6, 1, 3, 8, 4, 7, 5, 9, 0};
    printf("1.a.b Tampilkan hasil setiap iterasi dengan comparison, swapping dan movement - Bubble Sort: \n");

    printf("\nData sebelum sorting:\n");
    tampilkan(data, batas);

    bubbleSort(data, batas);

    printf("\nData setelah sorting:\n");
    tampilkan(data, batas);

    return 0;
}

// fungsi bubblesort
void bubbleSort(int data[], int batas) {
    int did_swap = 1; // inisialisasi jadi true
    int i, j, temp;
    int C = 0; // Comparison
    int S = 0; // Swapping
    int M = 0; // Movement

    for (i = 0; i < batas; i++) {
        printf("bagian ke-%d:\n", i);
        // bernilai true jika masih ada data yang diswap
        if (did_swap == 1) {
            did_swap = 0;   // reset menjadi false setiap awal proses bubble up
            // proses bubble up
            for (j = 0; j < batas - i - 1; j++) {
                C++;
                if (data[j] > data[j + 1]) {
                    // swap A[j] dan A[j+1]
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                    S++;
                    M += 3;
                    did_swap = 1;
                }
                // tampilkan hasil setiap iterasi
                if (did_swap == 1) {
                    printf("Iterasi ke-%d\n", j);
                    tampilkan(data, batas);
                }                
            }
        }
        if (did_swap == 0) printf("Tidak ada penukaran data\n");
        printf("\n");
    }
    printf("Total comparison (C) = %d\n", C);
    printf("Total swapping   (S) = %d\n", S);
    printf("Total movement   (M) = %d\n", M);
}

// fungsi menampilkan isi data
void tampilkan(int data[], int batas) {
    for (int i = 0; i < batas; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}
