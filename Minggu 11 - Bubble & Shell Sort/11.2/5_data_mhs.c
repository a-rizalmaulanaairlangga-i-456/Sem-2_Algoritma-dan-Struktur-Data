#include <stdio.h>
#include <string.h>

#define MAX 10
// Definisi struct siswa
typedef struct {
    int no;          
    char nama[50];   
    char nilai;      
} siswa;

siswa data[MAX];
siswa cadangan[MAX];
int batas;

// Deklarasi fungsi-fungsi
void menu();        // Selection / Insertion / Bubble / Shell
int mode_urut();    // Ascending / Descending
void insert_data();
void tampil();
void reset_array_data();
int urut();

void insertion_sort(int mode, int kriteria);
void selection_sort(int mode, int kriteria);
void bubble_sort(int mode, int kriteria);
void shell_sort(int mode, int kriteria);

// Fungsi Utama
int main() {
    printf("5. Menu sorting (Selection / Insertion / Bubble / Shell) dan mode urut (Ascending / Descending)\n");
    menu();
    return 0;
}

// Fungsi Menu
void menu() {
    int pilihan, mode, kriteria;

    insert_data();
    do {
        printf("\nMENU SORTING\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Bubble Sort\n");
        printf("4. Shell Sort\n");
        printf("5. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        if (pilihan >= 1 && pilihan <= 4) {
            reset_array_data();
            mode = mode_urut();     
            kriteria = urut();      // no / nama / nilai

            printf("\nData sebelum sorting:\n");
            tampil();

            switch (pilihan) {
                case 1: insertion_sort(mode, kriteria); break;
                case 2: selection_sort(mode, kriteria); break;
                case 3: bubble_sort(mode, kriteria); break;
                case 4: shell_sort(mode, kriteria); break;
            }
        }
    } while (pilihan != 5);
}

// Fungsi untuk memilih mode urut (ascending atau descending)
int mode_urut() {
    int mode;
    printf("Pilih mode urut:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilihan: ");
    scanf("%d", &mode);
    return mode;
}

void insert_data() {
    printf("Masukkan jumlah data siswa (maksimal 10 elemen): ");
    scanf("%d", &batas);

    for (int i = 0; i < batas; i++) {
        printf("Data siswa ke-%d\n", i + 1);
        printf("Nomor: ");
        scanf("%d", &data[i].no);
        printf("Nama: ");
        scanf(" %[^\n]", data[i].nama);
        printf("Nilai (A/B/C/D): ");
        scanf(" %c", &data[i].nilai);
        printf("\n");
    }

    for (int i = 0; i < batas; i++) {
        cadangan[i] = data[i];
    }
}

void tampil() {
    for (int i = 0; i < batas; i++) {
        printf("No    : %d\n", data[i].no);
        printf("Nama  : %s\n", data[i].nama);
        printf("Nilai : %c\n", data[i].nilai);
        printf("----------------------\n");
    }
    printf("\n");
}

void reset_array_data() {
    for (int i = 0; i < batas; i++) {
        data[i] = cadangan[i];
    }
}

// Fungsi Insertion Sort
void insertion_sort(int mode, int kriteria) {
    int depan, belakang;
    siswa key;

    for (depan = 1; depan < batas; depan++) {
        key = data[depan];
        belakang = depan - 1;

        while (belakang >= 0) {
            int banding = 0;

            if (kriteria == 1) // berdasarkan No
                banding = (mode == 1) ? data[belakang].no > key.no : data[belakang].no < key.no;
            else if (kriteria == 2) // berdasarkan Nama
                banding = (mode == 1) ? strcmp(data[belakang].nama, key.nama) > 0 : strcmp(data[belakang].nama, key.nama) < 0;
            else if (kriteria == 3) // berdasarkan Nilai
                banding = (mode == 1) ? data[belakang].nilai > key.nilai : data[belakang].nilai < key.nilai;

            if (!banding) break;

            data[belakang + 1] = data[belakang];
            belakang--;
        }
        data[belakang + 1] = key;
    }

    printf("Hasil setelah Insertion Sort:\n");
    tampil();
}

// Fungsi Selection Sort
void selection_sort(int mode, int kriteria) {
    int awal, cari, key;
    siswa temp;

    for (awal = 0; awal < batas - 1; awal++) {
        key = awal;
        for (cari = awal + 1; cari < batas; cari++) {
            int banding = 0;
            if (kriteria == 1)  // No
                banding = data[cari].no - data[key].no;
            else if (kriteria == 2)  // Nama
                banding = strcmp(data[cari].nama, data[key].nama);
            else if (kriteria == 3)  // Nilai
                banding = data[cari].nilai - data[key].nilai;

            if ((mode == 1 && banding < 0) || (mode == 2 && banding > 0))
                key = cari;
        }

        if (key != awal) {
            temp = data[awal];
            data[awal] = data[key];
            data[key] = temp;
        }
    }

    printf("Hasil setelah Selection Sort:\n");
    tampil();
}

// Fungsi Bubble Sort
void bubble_sort(int mode, int kriteria) {
    int i, j;
    siswa temp;

    for (i = 0; i < batas - 1; i++) {
        for (j = 0; j < batas - i - 1; j++) {
            int banding = 0;
            if (kriteria == 1)
                banding = data[j].no - data[j + 1].no;
            else if (kriteria == 2)
                banding = strcmp(data[j].nama, data[j + 1].nama);
            else if (kriteria == 3)
                banding = data[j].nilai - data[j + 1].nilai;

            if ((mode == 1 && banding > 0) || (mode == 2 && banding < 0)) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    printf("Hasil setelah Bubble Sort:\n");
    tampil();
}

// Fungsi Shell Sort
void shell_sort(int mode, int kriteria) {
    int gap, i, j;
    siswa temp;

    for (gap = batas / 2; gap > 0; gap /= 2) {
        for (i = gap; i < batas; i++) {
            temp = data[i];
            j = i;

            int banding = 0;
            while (j >= gap) {
                if (kriteria == 1)
                    banding = data[j - gap].no - temp.no;
                else if (kriteria == 2)
                    banding = strcmp(data[j - gap].nama, temp.nama);
                else if (kriteria == 3)
                    banding = data[j - gap].nilai - temp.nilai;

                if ((mode == 1 && banding > 0) || (mode == 2 && banding < 0)) {
                    data[j] = data[j - gap];
                    j -= gap;
                } else break;
            }
            data[j] = temp;
        }
    }

    printf("Hasil setelah Shell Sort:\n");
    tampil();
}

// Fungsi untuk memilih urutan berdasarkan No, Nama, atau Nilai
int urut() {
    int pilihan;
    printf("Pengurutan berdasarkan:\n");
    printf("1. No\n");
    printf("2. Nama\n");
    printf("3. Nilai\n");
    printf("Pilihan anda [1/2/3]: ");
    scanf("%d", &pilihan);
    return pilihan;
}
