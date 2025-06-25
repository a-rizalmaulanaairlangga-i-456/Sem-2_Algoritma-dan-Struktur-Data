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
void menu();        // Selection / Insertion
int mode_urut();    // Ascending / Descending
void insert_data();
void tampil();
void reset_array_data();
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

    insert_data();
    do {
        printf("\nMENU SORTING\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        if (pilihan == 1 || pilihan == 2) {
            reset_array_data();
            mode = mode_urut();

            printf("\n");
            printf("Data sebelum sorting:\n");
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

void insert_data() {
    printf("Masukkan jumlah data siswa (maksimal 10 elemen): ");
    scanf("%d", &batas);

    for (int i = 0; i < batas; i++) {
        printf("Data siswa ke-%d\n", i + 1);
        printf("Nomor: ");
        scanf("%d", &data[i].no);
        printf("Nama: ");
        scanf(" %[^\n]", data[i].nama);  // pakai spasi di depan %[^\n] untuk menangkap spasi
        printf("Nilai (A/B/C/D): ");
        scanf(" %c", &data[i].nilai);    // spasi supaya tidak terbaca newline sisa input
        printf("\n");
    }

    // Copy semua isi Data ke Backup
    for (int i = 0; i < batas; i++) {
        cadangan[i] = data[i];
    }
}
// Fungsi untuk menampilkan array
void tampil() {
    for (int i = 0; i < batas; i++) {
        printf("No    : %d\n", data[i].no);
        printf("Nama  : %s\n", data[i].nama);
        printf("Nilai : %c\n", data[i].nilai);
        printf("----------------------\n");
    }
    printf("\n");
}

// Fungsi baru untuk reset array dari backup
void reset_array_data() {
    // Copy semua isi Data ke Backup
    for (int i = 0; i < batas; i++) {
        data[i] = cadangan[i];
    }
}

// Fungsi Insertion Sort
void insertion_sort(int mode) {
    int depan, belakang, c = 0, s = 0; // c: comparison, s: swapping
    siswa key;

    for (depan = 1; depan < batas; depan++) {
        key = data[depan];     // Assign elemen array indeks depan ke key
        belakang = depan - 1;      // Inisialisasi belakang untuk pembandingan

        if (mode == 1) { // Ascending
            // Bandingkan elemen array pada indeks belakang > key
            while (belakang >= 0 && data[belakang].no > key.no) {
                c++;
                data[belakang + 1] = data[belakang]; // Pindahkan elemen tersebut ke 1 posisi berikutnya
                belakang--;
                s++;
            }
        } else { // Descending
            // Bandingkan elemen array pada indeks belakang < key
            while (belakang >= 0 && data[belakang].no < key.no) {
                c++;
                data[belakang + 1] = data[belakang]; // Pindahkan elemen tersebut ke 1 posisi berikutnya
                belakang--;
                s++;
            }
        }
        data[belakang + 1] = key;   // Assign key kembali ke array
        s++;
    }

    printf("Hasil setelah Insertion Sort:\n");
    tampil();
    printf("Jumlah comparison: %d\n", c);
    printf("Jumlah swapping: %d\n", s);
}

// Fungsi Selection Sort
void selection_sort(int mode) {
    int awal, cari, key, c = 0, s = 0; // c: comparison, s: swapping
    siswa temp;

    for (awal = 0; awal < batas - 1; awal++) {
        key = awal;           // Inisialisasi dengan indeks awal

        for (cari = awal + 1; cari < batas; cari++) {
            c++;
            // Bandingkan array didepannya apakah lebih kecil/besar dengan array yang dianggap kecil/besar sebelumnya
            if ((mode == 1 && data[cari].no < data[key].no) || (mode == 2 && data[cari].no > data[key].no)) {
                key = cari;           // Dapatkan indeks yang dicari ke key
            }
        }

        // Swap struct langsung
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

