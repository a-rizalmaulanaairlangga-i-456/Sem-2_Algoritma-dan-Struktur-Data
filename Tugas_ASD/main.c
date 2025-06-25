#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

int data[ELEMEN_MAKS], data_temp[ELEMEN_MAKS], jumlah_data;
int jarak_shell[] = {701, 301, 132, 57, 23, 10, 4, 1};

// Deklarasi fungsi
void buat_data_acak();
void salin_data();
void menu_pengurutan();

int main() {
    printf("Masukkan jumlah data (minimal 25000): ");
    scanf("%d", &jumlah_data);

    if (jumlah_data < 25000 || jumlah_data > ELEMEN_MAKS) {
        printf("Jumlah data tidak valid. Harus antara 25000 sampai %d.\n", ELEMEN_MAKS);
        return 1;
    }

    buat_data_acak(); // Buat data acak awal
    menu_pengurutan(); // Masuk ke menu pengurutan
    return 0;
}

// Fungsi membuat data acak
void buat_data_acak() {
    srand(time(NULL));
    for (int indeks = 0; indeks < ELEMEN_MAKS; indeks++) {
        data_temp[indeks] = rand();
    }
    printf("Data acak baru telah dibuat.\n");
}

// Fungsi menyalin isi array dari data_temp ke data
void salin_data() {
    for (int i = 0; i < ELEMEN_MAKS; i++) {
        data[i] = data_temp[i];
    }
}

// Fungsi menu utama untuk memilih metode sorting
void menu_pengurutan() {
    int pilihan;
    clock_t mulai, selesai;
    double waktu;

    do {
        printf("\n===== MENU PENGURUTAN =====\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Shell Sort\n");
        printf("4. Bubble Sort\n");
        printf("5. Merge Sort\n");
        printf("6. Quick Sort\n");
        printf("7. Buat Data Acak Baru\n");
        printf("0. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);
        

        if (pilihan >= 1 && pilihan <= 6) {
            // Salin data_temp ke data agar data acak tetap
            salin_data();

            mulai = clock();
            switch (pilihan) {
                case 1:
                    pengurutan_insertion(data, 1, jumlah_data);
                    break;
                case 2:
                    pengurutan_selection(data, jumlah_data);
                    break;
                case 3:
                    pengurutan_shell(data, jumlah_data, jarak_shell, sizeof(jarak_shell) / sizeof(jarak_shell[0]));
                    break;
                case 4:
                    pengurutan_bubble(data, 1, jumlah_data);
                    break;
                case 5:
                    pengurutan_merge(data, jumlah_data);
                    break;
                case 6:
                    pengurutan_quick(data, jumlah_data);
                    break;
            }
            selesai = clock();
            waktu = (double)(selesai - mulai) / CLOCKS_PER_SEC;
            printf("Waktu komputasi: %.6f detik\n", waktu);

        } else if (pilihan == 7) {
            buat_data_acak();
        } else if (pilihan == 0) {
            printf("Program selesai.\n");
        } else {
            printf("Pilihan tidak valid!\n");
        }
        
    } while (pilihan != 0);
}