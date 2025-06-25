#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fungsi faktorial dengan iterasi
unsigned long long faktorial_iterasi(int );
// Fungsi faktorial dengan rekursif biasa
unsigned long long faktorial_rekursi(int );
// Fungsi faktorial dengan rekursif tail
unsigned long long faktorial_tail(int , unsigned long long );

// Fungsi utama
int main() {
    int pilihan, n;
    unsigned long long hasil;
    // deklarasi variabel untuk menentukan waktu
    clock_t start, end;
    double waktukomputasi;

    // Menampilkan menu
    while (1) {
        printf("\nPilih metode faktorial:\n");
        printf("1. Iterasi\n");
        printf("2. Rekursi\n");
        printf("3. Rekursi Tail\n");
        printf("4. Bandingkan waktu komputasi\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        if (pilihan == 5) break;

        // Jika pilihan mena
        if (pilihan >= 1 && pilihan <= 3) {
            printf("Masukkan bilangan bulat positif: ");
            scanf("%d", &n);
        }

        // Penentuan
        switch (pilihan) {
            case 1:
                start = clock();
                hasil = faktorial_iterasi(n);
                end = clock();
                waktukomputasi= (double)(end - start) / CLOCKS_PER_SEC;

                printf("Hasil faktorial (iterasi): %llu\n", hasil);
                printf("Waktu komputasi: %f detik\n", waktukomputasi);
                break;

            case 2:
                start = clock();
                hasil = faktorial_rekursi(n);
                end = clock();
                waktukomputasi= (double)(end - start) / CLOCKS_PER_SEC;

                printf("Hasil faktorial (rekursi): %llu\n", hasil);
                printf("Waktu komputasi: %f detik\n", waktukomputasi);
                break;

            case 3:
                start = clock();
                faktorial_tail(n, 1);
                end = clock();
                waktukomputasi= (double)(end - start) / CLOCKS_PER_SEC;

                printf("Waktu komputasi: %f detik\n", waktukomputasi);
                break;

            // Pilihan 4 akan menjalankan semua jenis faktorial, hanya memfokuskan pada perbandingan waktu komputasi
            case 4:
                printf("Masukkan bilangan bulat besar untuk pembandingan (kasih angka besar bolo): ");
                scanf("%d", &n);

                start = clock();
                faktorial_iterasi(n);
                end = clock();
                waktukomputasi= (double)(end - start) / CLOCKS_PER_SEC;
                printf("Iterasi: %f detik\n", waktukomputasi);

                start = clock();
                faktorial_rekursi(n);
                end = clock();
                waktukomputasi= (double)(end - start) / CLOCKS_PER_SEC;
                printf("Rekursi: %f detik\n", waktukomputasi);

                start = clock();
                faktorial_tail(n, 1);
                end = clock();
                waktukomputasi= (double)(end - start) / CLOCKS_PER_SEC;
                printf("Rekursi Tail: %f detik\n", waktukomputasi);
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }
    }

    return 0;
}

// Fungsi faktorial dengan iterasi
unsigned long long faktorial_iterasi(int n) {
    unsigned long long hasil = 1;
    for (int i = 2; i <= n; i++) {
        hasil *= i;
    }
    return hasil;
}

// Fungsi faktorial dengan rekursif biasa
unsigned long long faktorial_rekursi(int n) {
    if (n <= 1)
        return 1;
    else
        return n * faktorial_rekursi(n - 1);
}

// Fungsi faktorial dengan rekursif tail
unsigned long long faktorial_tail(int n, unsigned long long done) {
    if (n <= 1) {
        printf("Hasil faktorial (rekursi tail): %llu\n", done);
        return done;
    } else {
        return faktorial_tail(n - 1, n * done);
    }
}
