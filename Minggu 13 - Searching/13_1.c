#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

#define MAKS 100000000

long long data[MAKS], data_asli[MAKS];
long long jumlah_data;

// deklarasi fungsi
void tukar(long long *a, long long *b);
void quick_sort(long long data[], long long kiri, long long kanan);
void generate_data();
void salin_data();
long long sequential_search(long long key);
long long binary_search(long long key);
void menu();

// Fungsi main
long long main() {
    menu();
    return 0;
}

// Fungsi tukar
void tukar(long long *a, long long *b) {
    long long temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi Quick Sort
void quick_sort(long long data[], long long kiri, long long kanan) {
    if (kiri < kanan) {
        long long pivot = data[kanan];
        long long i = kiri - 1;
        for (long long j = kiri; j < kanan; j++) {
            if (data[j] <= pivot) {
                i++;
                tukar(&data[i], &data[j]);
            }
        }
        tukar(&data[i + 1], &data[kanan]);
        long long pivotIndex = i + 1;

        quick_sort(data, kiri, pivotIndex - 1);
        quick_sort(data, pivotIndex + 1, kanan);
    }
}

// Fungsi untuk generate data acak
void generate_data() {
    for (long long i = 0; i < jumlah_data; i++) {
        data_asli[i] = rand();
    }
}

// Menyalin data asli ke data untuk digunakan search
void salin_data() {
    for (long long i = 0; i < jumlah_data; i++) {
        data[i] = data_asli[i];
    }
}

// Sequential Search unsorted array
long long sequential_search(long long key) {
    for (long long i = 0; i < jumlah_data; i++) {
        if (data[i] == key) return i;
    }
    return -1;
}

// Binary Search sorted array
long long binary_search(long long key) {
    long long kiri = 0, kanan = jumlah_data - 1;
    while (kiri <= kanan) {
        long long tengah = (kiri + kanan) / 2;
        if (data[tengah] == key) return tengah;
        else if (key < data[tengah]) kanan = tengah - 1;
        else kiri = tengah + 1;
    }
    return -1;
}

// Menu utama
void menu() {
    int pilihan, key, hasil;
    LARGE_INTEGER start, end, freq;
    double waktu;

    while (1) {+
        printf("\n===== MENU SEARCHING =====\n");
        printf("1. Generate Data Acak Baru\n");
        printf("2. Sequential Search (Unsorted Array)\n");
        printf("3. Sequential Search (Sorted Array)\n");
        printf("4. Binary Search (Sorted Array)\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                printf("Masukkan jumlah data: ");
                scanf("%d", &jumlah_data);
                generate_data();
                printf("Data acak baru berhasil dibuat.\n");
                break;

            case 2:
                salin_data();
                printf("Masukkan data yang ingin dicari: ");
                scanf("%d", &key);
                QueryPerformanceFrequency(&freq);
                QueryPerformanceCounter(&start);
                hasil = sequential_search(key);
                QueryPerformanceCounter(&end);
                waktu = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
                if (hasil != -1)
                    printf("Data ditemukan pada indeks ke-%d\n", hasil);
                else
                    printf("Data tidak ditemukan.\n");
                printf("Waktu komputasi: %.6f detik\n", waktu);
                break;

            case 3:
                salin_data();
                quick_sort(data, 0, jumlah_data - 1);
                printf("Masukkan data yang ingin dicari: ");
                scanf("%d", &key);
                QueryPerformanceFrequency(&freq);
                QueryPerformanceCounter(&start);
                hasil = sequential_search(key);
                QueryPerformanceCounter(&end);
                waktu = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
                if (hasil != -1)
                    printf("Data ditemukan pada indeks ke-%d\n", hasil);
                else
                    printf("Data tidak ditemukan.\n");
                printf("Waktu komputasi: %.6f detik\n", waktu);
                break;

            case 4:
                salin_data();
                quick_sort(data, 0, jumlah_data - 1);
                printf("Masukkan data yang ingin dicari: ");
                scanf("%d", &key);
                QueryPerformanceFrequency(&freq);
                QueryPerformanceCounter(&start);
                hasil = binary_search(key);
                QueryPerformanceCounter(&end);
                waktu = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
                if (hasil != -1)
                    printf("Data ditemukan pada indeks ke-%d\n", hasil);
                else
                    printf("Data tidak ditemukan.\n");
                printf("Waktu komputasi: %.6f detik\n", waktu);
                break;

            case 5:
                printf("Keluar dari program.\n");
                return;

            default:
                printf("Pilihan tidak valid!\n");
        }
    }
}

