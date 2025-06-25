#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct siswa Node;
struct siswa {
    int no;
    char nama[20];
    float nilai;
    Node *next;
};
Node *head = NULL, *p;

// Fungsi utama
void menu();
void alokasi();
void cari_insert();
void cari_data();
void hapus_tertentu();
void tampil();
void hitung_rata_rata();

// Fungsi insert
void insert_awal();
void insert_akhir();
void insert_bef(Node *ptail, Node *tail);

// Fungsi delete
void bebaskan(Node *);

// Fungsi utama
int main(){
    menu();
    return 0;
}

// Fungsi untuk menampilkan menu
void menu() {
    int pilihan;
    do {
        printf("\n=== MENU DATA MAHASISWA ===\n");
        printf("1. Input Data Mahasiswa\n");
        printf("2. Cari Mahasiswa\n");
        printf("3. Hapus Mahasiswa\n");
        printf("4. Hitung Rata-Rata Nilai\n");
        printf("5. Keluar\n");
        printf("Pilih opsi (1-5): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                alokasi();
                cari_insert();
                tampil();
                break;
            case 2:
                cari_data();
                break;
            case 3:
                hapus_tertentu();
                break;
            case 4:
                hitung_rata_rata();
                break;
            case 5:
                printf("Keluar dari program...\n");
                tampil();
                exit(0);
            default:
                printf("Pilihan tidak valid! Silakan pilih lagi.\n");
        }
    } while (pilihan != 5);
}

// Fungsi untuk mengalokasikan node baru (sesuai permintaan)
void alokasi(){
    p = (Node *) malloc(sizeof(Node));
    if(p == NULL){
        printf("Memory tidak tersedia\n");
        exit(0);
    } else {
        printf("\nMasukkan Data Mahasiswa:\n");

        printf("No\t\t: ");
        scanf("%d", &p->no);
        fflush(stdin);

        printf("Nama\t\t: ");
        fgets(p->nama, sizeof(p->nama), stdin);
        p->nama[strcspn(p->nama, "\n")] = 0;

        printf("Nilai\t\t: ");
        scanf("%f", &p->nilai);
        p->next = NULL;
    }
}

// Fungsi untuk menampilkan isi linked list
void tampil(){
    Node *baca;
    printf("\nData yang telah diinputkan:\n");
    baca = head;

    if (baca == NULL) {
        printf("SLL kosong.\n\n");
        return;
    }

    printf("No\t\tNama\t\tNilai\n");
    while (baca != NULL){   
        printf("%d\t\t", baca->no);
        printf("%s\t\t", baca->nama);
        printf("%.2f\n", baca->nilai);
        baca = baca->next;
    }
    printf("\n");
}

// Fungsi untuk menentukan posisi penyisipan data
void cari_insert(){
    Node *tail, *ptail = NULL;

    if(head == NULL) { // Jika linked list masih kosong
        head = p;
    } else if(p->no < head->no) { // Jika data lebih kecil dari head
        insert_awal();
    } else {
        tail = head;
        while (tail != NULL && p->no >= tail->no) { 
            ptail = tail;
            tail = tail->next;
        }
        if (tail == NULL) // Jika data terbesar, masukkan di akhir
            insert_akhir();
        else
            insert_bef(ptail, tail); // Jika data ada di tengah
    }
}

// Fungsi untuk menyisipkan node di awal
void insert_awal(){
    p->next = head;
    head = p;
}

// Fungsi untuk menyisipkan node di akhir
void insert_akhir(){
    Node *tail = head;

    while (tail->next != NULL)
        tail = tail->next;
    tail->next = p;
}

// Fungsi untuk menyisipkan node di tengah sebelum `tail`
void insert_bef(Node *ptail, Node *tail){
    p->next = tail;
    ptail->next = p;
}

// Fungsi untuk mencari data dalam linked list
void cari_data(){
    int cari;
    Node *baca = head;

    if (head == NULL) {
        printf("List kosong, tidak ada data untuk dicari.\n");
        return;
    }

    printf("\nMasukkan Nomor Mahasiswa yang ingin dicari: ");
    scanf("%d", &cari);

    while (baca != NULL) {
        if (baca->no == cari) {
            printf("\nMahasiswa ditemukan:\n");
            printf("No\t\tNama\t\tNilai\n");
            printf("%d\t\t%s\t\t%.2f\n", baca->no, baca->nama, baca->nilai);
            return;
        }
        baca = baca->next;
    }

    printf("Mahasiswa dengan nomor %d tidak ditemukan.\n", cari);
}

// Fungsi untuk menghapus data
void hapus_tertentu(){
    Node *hapus, *prevHapus;
    int key;

    if (head == NULL) {
        printf("List kosong, tidak ada data untuk dihapus.\n");
        return;
    }

    printf("\nMasukkan Nomor Mahasiswa yang mau dihapus: ");
    scanf("%d", &key);
    hapus = head;

    if (hapus->no == key) { // Jika yang dihapus adalah head
        head = hapus->next;
        bebaskan(hapus);
    } else {
        while (hapus != NULL && hapus->no != key) {
            prevHapus = hapus;
            hapus = hapus->next;
        }
        if (hapus == NULL) {
            printf("Mahasiswa dengan nomor %d tidak ditemukan.\n", key);
            return;
        }
        prevHapus->next = hapus->next;
        bebaskan(hapus);
    }

    printf("Mahasiswa dengan nomor %d telah dihapus.\n", key);
    tampil();
}

// Fungsi membebaskan memori
void bebaskan(Node *x){
    free(x);
}

// Fungsi untuk menghitung nilai rata-rata
void hitung_rata_rata(){
    Node *baca = head;
    float total = 0;
    int jumlah = 0;

    if (head == NULL) {
        printf("List kosong, tidak ada nilai untuk dihitung.\n");
        return;
    }

    while (baca != NULL) {
        total += baca->nilai;
        jumlah++;
        baca = baca->next;
    }

    printf("\nRata-rata nilai mahasiswa: %.2f\n", total / jumlah);
}
