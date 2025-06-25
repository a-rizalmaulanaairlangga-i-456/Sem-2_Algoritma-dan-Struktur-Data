#include <stdio.h>

// deklarasi fungint data[], int batassi sort
void bubbleSort(int data[], int batas);
    // fungsi pendukung tambahan
void input_data(int data[], int batas);
void tampilkan(int data[], int batas);


// fungsi utama
int main() {
    int batas;
    printf("Bubble Sort: \n");

    printf("Masukkan jumlah data: ");
    scanf("%d", &batas);

    int data[batas];
    input_data(data, batas);

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

    for (i = 0; i < batas; i++) {
        // bernilai true jika masih ada data yang diswap
        if (did_swap == 1) {
            did_swap = 0;   // reset menjadi false setiap awal proses bubble up
            // proses bubble up
            for (j = 0; j < batas - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    // swap A[j] dan A[j+1]
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                    did_swap = 1;
                }
            }
        }
    }
}

// Fungsi input data
void input_data(int data[], int batas) {
    printf("Masukkan %d elemen:\n", batas);
    for (int i = 0; i < batas; i++) {
        printf("Data ke-%d: ", i + 1);
        scanf("%d", &data[i]);
    }
}

// fungsi menampilkan isi data
void tampilkan(int data[], int batas) {
    for (int i = 0; i < batas; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}
