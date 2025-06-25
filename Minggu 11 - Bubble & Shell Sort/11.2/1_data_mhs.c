#include <stdio.h>

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

void insertion_sort(int mode);
void selection_sort(int mode);
void bubble_sort(int mode);
void shell_sort(int mode);

// Fungsi Utama
int main() {
    printf("1. Menu sorting (Selection / Insertion / Bubble / Shell) dan mode urut (Ascending / Descending)\n");
    menu();
    return 0;
}

// Fungsi Menu
void menu() {
    int pilihan, mode;

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

            printf("\nData sebelum sorting:\n");
            tampil();

            switch (pilihan) {
                case 1: insertion_sort(mode); break;
                case 2: selection_sort(mode); break;
                case 3: bubble_sort(mode); break;
                case 4: shell_sort(mode); break;
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
void insertion_sort(int mode) {
    int depan, belakang, c = 0, s = 0;
    siswa key;

    for (depan = 1; depan < batas; depan++) {
        key = data[depan];
        belakang = depan - 1;

        while (belakang >= 0 &&
            ((mode == 1 && data[belakang].no > key.no) ||
             (mode == 2 && data[belakang].no < key.no))) {
            c++;
            data[belakang + 1] = data[belakang];
            belakang--;
            s++;
        }
        data[belakang + 1] = key;
        s++;
    }

    printf("Hasil setelah Insertion Sort:\n");
    tampil();
    printf("Jumlah comparison: %d\n", c);
    printf("Jumlah swapping: %d\n", s);
}

// Fungsi Selection Sort
void selection_sort(int mode) {
    int awal, cari, key, c = 0, s = 0;
    siswa temp;

    for (awal = 0; awal < batas - 1; awal++) {
        key = awal;

        for (cari = awal + 1; cari < batas; cari++) {
            c++;
            if ((mode == 1 && data[cari].no < data[key].no) ||
                (mode == 2 && data[cari].no > data[key].no)) {
                key = cari;
            }
        }

        if (key != awal) {
            temp = data[awal];
            data[awal] = data[key];
            data[key] = temp;
            s++;
        }
    }

    printf("Hasil setelah Selection Sort:\n");
    tampil();
    printf("Jumlah comparison: %d\n", c);
    printf("Jumlah swapping: %d\n", s);
}

// Fungsi Bubble Sort
void bubble_sort(int mode) {
    int c = 0, s = 0;
    siswa temp;
    for (int i = 0; i < batas - 1; i++) {
        for (int j = 0; j < batas - i - 1; j++) {
            c++;
            if ((mode == 1 && data[j].no > data[j + 1].no) ||
                (mode == 2 && data[j].no < data[j + 1].no)) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                s++;
            }
        }
    }

    printf("Hasil setelah Bubble Sort:\n");
    tampil();
    printf("Jumlah comparison: %d\n", c);
    printf("Jumlah swapping: %d\n", s);
}

// Fungsi Shell Sort
void shell_sort(int mode) {
    int gap = batas / 2, c = 0, s = 0;
    siswa temp;

    while (gap > 0) {
        for (int i = gap; i < batas; i++) {
            temp = data[i];
            int j = i;
            while (j >= gap &&
                ((mode == 1 && data[j - gap].no > temp.no) ||
                 (mode == 2 && data[j - gap].no < temp.no))) {
                c++;
                data[j] = data[j - gap];
                j -= gap;
                s++;
            }
            data[j] = temp;
            s++;
        }
        gap /= 2;
    }

    printf("Hasil setelah Shell Sort:\n");
    tampil();
    printf("Jumlah comparison: %d\n", c);
    printf("Jumlah swapping: %d\n", s);
}
