#include <stdio.h>

#define MAX 100

int Data[10] = {2, 6, 1, 3, 8, 4, 7, 5, 9, 0};
int hasil[MAX];

// Deklarasi fungsi
void MergeSortRekursif(int left, int right);
void Merge(int left, int median, int right);
void tampilkan(int data[], int n);

int main() {
    int n = 10;
    // printf("Masukkan jumlah data (maks %d): ", MAX);
    // scanf("%d", &n);

    // printf("Masukkan %d data:\n", n);
    // for (int i = 0; i < n; i++) {
    //     printf("Data[%d] = ", i);
    //     scanf("%d", &Data[i]);
    // }

    printf("\nData sebelum diurutkan:\n");
    tampilkan(Data, n);

    MergeSortRekursif(0, n - 1);

    printf("\nData setelah diurutkan (Merge Sort):\n");
    tampilkan(Data, n);

    return 0;
}

// Fungsi MergeSort Rekursif
void MergeSortRekursif(int left, int right) {
    if (left < right) {
        int med = (left + right) / 2;
        MergeSortRekursif(left, med);
        MergeSortRekursif(med + 1, right);

        Merge(left, med, right);
    }
}

// Fungsi Merge (penggabungan 2 bagian terurut)
void Merge(int left, int median, int right) {
    int kiri1 = left;
    int kanan1 = median;
    int kiri2 = median + 1;
    int kanan2 = right;
    int i = left;

    // Proses penggabungan dua bagian terurut
    while (kiri1 <= kanan1 && kiri2 <= kanan2) {
        if (Data[kiri1] <= Data[kiri2]) {
            hasil[i] = Data[kiri1];
            kiri1++;
        } else {
            hasil[i] = Data[kiri2];
            kiri2++;
        }
        i++;
    }

    // Sisa elemen kiri1 (jika ada)
    while (kiri1 <= kanan1) {
        hasil[i] = Data[kiri1];
        kiri1++;
        i++;
    }

    // Sisa elemen kiri2 (jika ada)
    while (kiri2 <= kanan2) {
        hasil[i] = Data[kiri2];
        kiri2++;
        i++;
    }

    // Salin hasil kembali ke Data asli
    for (int j = left; j <= right; j++) {
        Data[j] = hasil[j];
    }
}

// Fungsi menampilkan data
void tampilkan(int data[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}
