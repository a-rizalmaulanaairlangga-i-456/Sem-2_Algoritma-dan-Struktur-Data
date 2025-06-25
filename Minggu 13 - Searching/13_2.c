#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int no;
    char nama[50];
    char nilai;
} siswa;

siswa data[MAX];
siswa cadangan[MAX];
int batas;

// Deklarasi fungsi
void tukar(siswa *a, siswa *b);
void quick_sort(siswa arr[], int kiri, int kanan, int by_field);
void insert_data();
void tampil();
void tampil_siswa(int index);
void reset_array_data();
int sequential_search(int field, char *key_str, int key_int);
int binary_search(int field, char *key_str, int key_int);
int jenis_pencarian();
int metode_pencarian(int *key_int, char *key_str);
void menu_urut();
void menu();


// Fungsi main
int main() {
    menu();
    return 0;
}

// Fungsi tukar
void tukar(siswa *a, siswa *b) {
    siswa temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi Quick Sort dengan parameter field (1: no, 2: nama, 3: nilai)
void quick_sort(siswa arr[], int kiri, int kanan, int by_field) {
    if (kiri < kanan) {
        siswa pivot = arr[kanan];
        int i = kiri - 1;
        
        for (int j = kiri; j < kanan; j++) {
            int compare_result = 0;
            
            switch(by_field) {
                case 1: // Sort by no
                    compare_result = (arr[j].no <= pivot.no);
                    break;
                case 2: // Sort by nama
                    compare_result = (strcmp(arr[j].nama, pivot.nama) <= 0);
                    break;
                case 3: // Sort by nilai
                    compare_result = (arr[j].nilai <= pivot.nilai);
                    break;
            }
            
            if (compare_result) {
                i++;
                tukar(&arr[i], &arr[j]);
            }
        }
        tukar(&arr[i + 1], &arr[kanan]);
        int pivotIndex = i + 1;

        quick_sort(arr, kiri, pivotIndex - 1, by_field);
        quick_sort(arr, pivotIndex + 1, kanan, by_field);
    }
}

// Fungsi untuk input data
void insert_data() {
    printf("Masukkan jumlah data siswa (maksimal %d elemen): ", MAX);
    scanf("%d", &batas);

    for (int i = 0; i < batas; i++) {
        printf("\nData siswa ke-%d\n", i + 1);
        printf("Nomor: ");
        scanf("%d", &data[i].no);
        printf("Nama: ");
        scanf(" %[^\n]", data[i].nama);
        printf("Nilai (A/B/C/D): ");
        scanf(" %c", &data[i].nilai);
        strupr(&data[i].nilai);
    }

    // Salin ke cadangan
    for (int i = 0; i < batas; i++) {
        cadangan[i] = data[i];
    }
    
    printf("\nData berhasil dimasukkan.\n");
}

// Fungsi untuk menampilkan data
void tampil() {
    printf("\nDaftar Mahasiswa:\n");
    printf("========================================\n");
    for (int i = 0; i < batas; i++) {
        printf("No    : %d\n", data[i].no);
        printf("Nama  : %s\n", data[i].nama);
        printf("Nilai : %c\n", data[i].nilai);
        printf("----------------------------------------\n");
    }
}

// Fungsi untuk menampilkan satu data siswa
void tampil_siswa(int index) {
    if (index >= 0 && index < batas) {
        printf("No    : %d\n", data[index].no);
        printf("Nama  : %s\n", data[index].nama);
        printf("Nilai : %c\n", data[index].nilai);
    }
}

// Fungsi untuk reset data ke keadaan semula
void reset_array_data() {
    for (int i = 0; i < batas; i++) {
        data[i] = cadangan[i];
    }
}

// Sequential Search pada array belum terurut
// field: 1 (no), 2 (nama), 3 (nilai)
int sequential_search(int field, char *key_str, int key_int) {
    for (int i = 0; i < batas; i++) {
        int found = 0;
        
        switch(field) {
            case 1: // Search by no
                if (data[i].no == key_int) found = 1;
                break;
            case 2: // Search by nama
                if (strcmp(data[i].nama, key_str) == 0) found = 1;
                break;
            case 3: // Search by nilai
                if (data[i].nilai == key_str[0]) found = 1;
                break;
        }
        
        if (found) return i;
    }
    return -1;
}

// Binary Search pada array terurut
int binary_search(int field, char *key_str, int key_int) {
    int kiri = 0, kanan = batas - 1;
    
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        int compare_result = 0;
        
        switch(field) {
            case 1: // Search by no
                if (data[tengah].no == key_int) return tengah;
                compare_result = (key_int < data[tengah].no) ? -1 : 1;
                break;
            case 2: // Search by nama
                compare_result = strcmp(data[tengah].nama, key_str);
                if (compare_result == 0) return tengah;
                break;
            case 3: // Search by nilai
                if (data[tengah].nilai == key_str[0]) return tengah;
                compare_result = (key_str[0] < data[tengah].nilai) ? -1 : 1;
                break;
        }
        
        if (compare_result < 0) {
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }
    return -1;
}

// Fungsi untuk memilih jenis pencarian
int jenis_pencarian() {
    int jenis;
    printf("\nMenu Searching:\n");
    printf("1. Sequential Search (Unsorted Array)\n");
    printf("2. Binary Search (Sorted Array)\n");
    printf("Pilihan: ");
    scanf("%d", &jenis);
    return jenis;
}

// Fungsi untuk memilih field pencarian dan mengisi nilai kunci
int metode_pencarian(int *key_int, char *key_str) {
    int field;
    printf("\nPilih field untuk pencarian:\n");
    printf("1. Nomor\n");
    printf("2. Nama\n");
    printf("3. Nilai\n");
    printf("Pilihan: ");
    scanf("%d", &field);

    switch (field) {
        case 1:
            printf("Masukkan nomor yang dicari: ");
            scanf("%d", key_int);
            break;
        case 2:
            printf("Masukkan nama yang dicari: ");
            scanf(" %[^\n]", key_str);
            break;
        case 3:
            printf("Masukkan nilai yang dicari (A/B/C/D): ");
            scanf(" %c", key_str);
            strupr(key_str);
            break;
        default:
            printf("Pilihan tidak valid.\n");
            return -1;
    }
    return field;
}

// fungsi pilihan urut data
void menu_urut() {
    int pilih_urut;
    printf("\n== Bentuk Data ==\n");
    printf("1. Urut berdasarkan No\n");
    printf("2. Urut berdasarkan Nama\n");
    printf("3. Urut berdasarkan Nilai\n");
    printf("4. Tidak terurut\n");
    printf("Jawaban anda: ");
    scanf("%d", &pilih_urut);

    switch (pilih_urut) {
    case 1:
        quick_sort(data, 0, batas-1, 1);
        tampil();
        reset_array_data();
        break;
    case 2:
        quick_sort(data, 0, batas-1, 2);
        tampil();
        reset_array_data();
        break;
    case 3:
        quick_sort(data, 0, batas-1, 3);
        tampil();
        reset_array_data();
        break;
    case 4:
        tampil();
        break;
    default:
        break;
    }
}

void menu() {
    int pilihan, field, key_int, hasil, index;
    char key_str[50];

    while (1) {
        printf("\n===== MENU SEARCHING DATA MAHASISWA =====\n");
        printf("1. Input Data Mahasiswa\n");
        printf("2. Tampilkan Data Mahasiswa\n");
        printf("3. Sequential Search (Unsorted Array)\n");
        printf("4. Binary Search (Sorted Array)\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                insert_data();
                break;
                
            case 2:
                if (batas == 0) {
                    printf("Belum ada data. Silakan input data terlebih dahulu.\n");
                } else {
                    menu_urut();
                }
                break;
                
            case 3:
                if (batas == 0) {
                    printf("Belum ada data. Silakan input data terlebih dahulu.\n");
                    break;
                }
                field = metode_pencarian(&key_int, key_str);
                index = sequential_search(field, key_str, key_int);
                if (index != -1) {
                    printf("Data ditemukan pada index ke-%d.\n", index);
                    tampil_siswa(index);
                } else {
                    printf("Data tidak ditemukan.\n");
                }
                break;
                
            case 4:
                if (batas == 0) {
                    printf("Belum ada data. Silakan input data terlebih dahulu.\n");
                    break;
                }
                field = metode_pencarian(&key_int, key_str);
                index = binary_search(field, key_str, key_int);
                if (index != -1) {
                    printf("Data ditemukan pada index ke-%d.\n", index);
                    tampil_siswa(index);
                } else {
                    printf("Data tidak ditemukan.\n");
                }
                break;
                
            case 5:
                printf("Keluar dari program.\n");
                return;
                
            default:
                printf("Pilihan tidak valid!\n");
        }
    }
}