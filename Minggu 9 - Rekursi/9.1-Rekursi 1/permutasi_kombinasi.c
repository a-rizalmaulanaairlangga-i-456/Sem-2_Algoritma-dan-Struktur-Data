#include <stdio.h>
#include <stdlib.h>

// Deklarasi fungsi
int faktorial_rekursi(int);

// Menu utama
int main() {
    int n, r;
    long long permutasi, kombinasi;

    printf("=== Program Menghitung Permutasi dan Kombinasi ===\n");
    printf("Masukkan nilai n: ");
    scanf("%d", &n);
    printf("Masukkan nilai r: ");
    scanf("%d", &r);

    // Validasi input
    if (n < 0 || r < 0 || r > n) {
        printf("Input tidak valid. Pastikan n >= 0, r >= 0, dan n >= r.\n");
        return 1;
    }

    // Hitung faktorial menggunakan rekursi
    permutasi = faktorial_rekursi(n) / faktorial_rekursi(n - r);
    kombinasi = faktorial_rekursi(n) / (faktorial_rekursi(r) * faktorial_rekursi(n - r));

    // Tampilkan hasil
    printf("Permutasi (P(%d,%d)) = %lld\n", n, r, permutasi);
    printf("Kombinasi (C(%d,%d)) = %lld\n", n, r, kombinasi);

    return 0;
}

// Fungsi faktorial dengan rekursi
int faktorial_rekursi(int n) {
    if (n <= 1)
        return 1;
    return n * faktorial_rekursi(n - 1);
}
