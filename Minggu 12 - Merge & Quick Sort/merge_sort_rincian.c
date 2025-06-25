#include <stdio.h>

#define MAX 100

// Data yang akan diurutkan
int Data[10] = {2, 6, 1, 3, 8, 4, 7, 5, 9, 0};
int hasil[MAX];

// Deklarasi fungsi
void MergeSortRekursif(int left, int right);
void Merge(int left, int median, int right);
void tampilkan(int data[], int n);

int main() {
    int n = 10;

    printf("Data sebelum diurutkan:\n");
    tampilkan(Data, n);

    printf("\nMulai proses Merge Sort:\n");
    MergeSortRekursif(0, n - 1);

    printf("\nData setelah diurutkan (Merge Sort):\n");
    tampilkan(Data, n);

    return 0;
}

// Fungsi Merge Sort Rekursif
void MergeSortRekursif(int left, int right) {
    printf("MergeSortRekursif(left = %d, right = %d)\n", left, right);

    if (left < right) {
        int med = (left + right) / 2;

        printf("  Membagi menjadi:\n");
        printf("    Kiri : left = %d, med = %d\n", left, med);
        printf("    Kanan: med+1 = %d, right = %d\n", med + 1, right);

        MergeSortRekursif(left, med);
        MergeSortRekursif(med + 1, right);

        printf("  Menggabungkan bagian:\n");
        printf("    Left: %d to %d | Right: %d to %d\n", left, med, med + 1, right);
        printf("    Data sebelum merge: ");
        tampilkan(Data, 10);

        Merge(left, med, right);

        printf("    Data setelah merge : ");
        tampilkan(Data, 10);
        printf("\n");
    }
}

// Fungsi Merge (menggabungkan dua bagian yang sudah diurutkan)
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

    // Sisa elemen dari bagian kiri
    while (kiri1 <= kanan1) {
        hasil[i] = Data[kiri1];
        kiri1++;
        i++;
    }

    // Sisa elemen dari bagian kanan
    while (kiri2 <= kanan2) {
        hasil[i] = Data[kiri2];
        kiri2++;
        i++;
    }

    // Salin hasil kembali ke array Data
    for (int j = left; j <= right; j++) {
        Data[j] = hasil[j];
    }
}

// Fungsi menampilkan array
void tampilkan(int data[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}
