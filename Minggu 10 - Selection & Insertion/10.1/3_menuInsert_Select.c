#include <stdio.h>
#include <string.h> 

int batas;
int array[100];
int cadangan[100];

// Deklarasi fungsi-fungsi
void menu();        // Selection / Insertion
int mode_urut();    // Ascending / Descending
void insert_array();
void tampil();
void reset_array();
// Fungsi Utama
void insertion_sort(int mode);
void selection_sort(int mode);

// Fungsi Utama
int main() {
    printf("3. Menu sorting (Selection / Insertion) dan mode urut (Ascending / Descending)\n");

    menu();
    return 0;
}

// Fungsi Menu
void menu() {
    int pilihan, mode;

    insert_array();
    do {
        printf("\nMENU SORTING\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        if (pilihan == 1 || pilihan == 2) {
            reset_array();
            mode = mode_urut();

            printf("\n");
            printf("Array sebelum sorting:\n");
            tampil();

            if (pilihan == 1)
                insertion_sort(mode);
            else
                selection_sort(mode);
        }
    } while (pilihan != 3);
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

void insert_array() {
    printf("Masukkan jumlah elemen array (maksimal 100 elemen): ");
    scanf("%d", &batas);

    printf("Masukkan elemen array (ketikkan satu angka lalu tekan enter): \n");
    for (int i = 0; i < batas; i++) {
        scanf("%d", &array[i]);
    }
    memcpy(cadangan, array, sizeof(int) * batas);   // Duplikat lebih dulu isi array ke cadangan
}
// Fungsi untuk menampilkan array
void tampil() {
    for (int i = 0; i < batas; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Fungsi baru untuk reset array dari backup
void reset_array() {
    memcpy(array, cadangan, sizeof(int) * batas);
}

// Fungsi Insertion Sort
void insertion_sort(int mode) {
    int depan, belakang, key, c = 0, s = 0; // c: comparison, s: swapping

    for (depan = 1; depan < batas; depan++) {
        key = array[depan];     // Assign elemen array indeks depan ke key
        belakang = depan - 1;      // Inisialisasi belakang untuk pembandingan

        if (mode == 1) { // Ascending
            // Bandingkan elemen array pada indeks belakang > key
            while (belakang >= 0 && array[belakang] > key) {
                c++;
                array[belakang + 1] = array[belakang]; // Pindahkan elemen tersebut ke 1 posisi berikutnya
                belakang--;
                s++;
            }
        } else { // Descending
            // Bandingkan elemen array pada indeks belakang < key
            while (belakang >= 0 && array[belakang] < key) {
                c++;
                array[belakang + 1] = array[belakang]; // Pindahkan elemen tersebut ke 1 posisi berikutnya
                belakang--;
                s++;
            }
        }
        array[belakang + 1] = key;   // Assign key kembali ke array
        s++;
    }

    printf("Hasil setelah Insertion Sort:\n");
    tampil();
    printf("Jumlah comparison: %d\n", c);
    printf("Jumlah swapping: %d\n", s);
}

// Fungsi Selection Sort
void selection_sort(int mode) {
    int awal, cari, key, temp, c = 0, s = 0; // c: comparison, s: swapping

    for (awal = 0; awal < batas - 1; awal++) {
        key = awal;           // Inisialisasi dengan indeks awal

        for (cari = awal + 1; cari < batas; cari++) {
            c++;
            // Bandingkan array didepannya apakah lebih kecil/besar dengan array yang dianggap kecil/besar sebelumnya
            if ((mode == 1 && array[cari] < array[key]) || (mode == 2 && array[cari] > array[key])) {
                key = cari;           // Dapatkan indeks yang dicari ke key
            }
        }
        // Tukar elemen
        temp = array[awal];
        array[awal] = array[key];
        array[key] = temp;
        s++;
    }

    printf("Hasil setelah Selection Sort:\n");
    tampil();
    printf("Jumlah comparison: %d\n", c);
    printf("Jumlah swapping: %d\n", s);
}

