#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};
Node *head = NULL, *p;

// Fungsi utama
void menu();
void alokasi();
void cari_insert();
void cari_data();
void tampil();

// Fungsi insert
void insert_awal();
void insert_akhir();
void insert_bef(Node *ptail, Node *tail);

// Fungsi delete
void bebaskan(Node *);
void hapus_tertentu();

// Fungsi utama
int main(){
    puts("Single Linked List - Nilai Integer - Insert Urut, Pencarian Data, Hapus data\n\n");
    while (1)
    {
        fflush(stdin);
        menu();
        fflush(stdin);
    }

    return 0;
}

// Fungsi untuk menampilkan menu
void menu() {
    int pilihan;
    do {
        printf("\n=== MENU LINKED LIST ===\n");
        printf("1. Input Data\n");
        printf("2. Cari Data\n");
        printf("3. Hapus Data\n");
        printf("4. Keluar\n");
        printf("Pilih opsi (1-4): ");
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
                printf("Keluar dari program...\n");
                tampil();
                exit(0);
            default:
                printf("Pilihan tidak valid! Silakan pilih lagi.\n");
        }
    } while (pilihan != 4);
}

// Fungsi untuk mengalokasikan node baru
void alokasi(){
    int x;

    printf("Data yang ingin disimpan: ");
    scanf("%d", &x);

    p = (Node *) malloc(sizeof(Node));
    if(p == NULL){
        printf("Memory tidak tersedia\n");
        exit(0);
    } else {
        p->data = x;
        p->next = NULL;
    }
}

// Fungsi untuk menampilkan isi linked list
void tampil(){
    Node *baca = head;
    puts("Isi dalam SLL: ");
    while (baca != NULL){   
        printf("%d -> ", baca->data);
        baca = baca->next;
    }
    printf("NULL\n");
}

// Fungsi untuk menentukan posisi penyisipan data
void cari_insert(){
    Node *tail, *ptail = NULL;

    if(head == NULL) { // Jika linked list masih kosong
        head = p;
    } else if(p->data < head->data) { // Jika data lebih kecil dari head
        insert_awal();
    } else {
        tail = head;
        while (tail != NULL && p->data >= tail->data) { 
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
    int cari, count = 0;
    Node *baca = head;

    if (head == NULL) {
        printf("List kosong, tidak ada data untuk dicari.\n");
        return;
    }

    printf("Masukkan data yang ingin dicari: ");
    scanf("%d", &cari);

    while (baca != NULL) {
        if (baca->data == cari)
            count++;
        baca = baca->next;
    }

    if (count > 0)
        printf("%d ditemukan sebanyak %d kali.\n", cari, count);
    else
        printf("%d tidak ditemukan.\n", cari);
}

// Fungsi membebaskan data yang ingin dihapus
void bebaskan(Node *x){
    free(x);
    x = NULL;
}

// Fungsi untuk menghapus data pertama
void hapus_awal(){
    Node *hapus;

    hapus = head;
    if(hapus->next == NULL)
        head = NULL;
    else{
        head = hapus->next;
        bebaskan(hapus);
    }
}

// Fungsi mencari data yang ingin dihapus
void hapus_tertentu(){
    Node *hapus, *prevHapus;
    int key;

    if (head == NULL) {
        printf("List kosong, tidak ada data untuk dihapus.\n");
        return;
    }

    printf("Data yang mau dihapus: ");
    scanf("%d", &key);
    hapus = head;
    if(hapus->data == key)
        hapus_awal();
    else{
        while (hapus->data != key){
            if (hapus->next == NULL)
            {
                printf("%d tidak ada di dalam SLL\n\n", key);
                return;
            }else{
                prevHapus = hapus;
                hapus = hapus->next;
            }
            
        }
        prevHapus->next = hapus->next;
        bebaskan(hapus);
        
    }
    tampil();
}
