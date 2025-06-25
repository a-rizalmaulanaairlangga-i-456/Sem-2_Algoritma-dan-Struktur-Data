#include <stdio.h>
#include <stdlib.h>

// Struktur node untuk Single Linked List (SLL)
typedef struct siswa Node;
struct siswa {
    int no;
    char nama[20];
    float nilai;
    Node *next;
};

// Variabel global
Node *head = NULL, *p;

// Fungsi untuk mengalokasikan memori untuk node baru
void alokasi(){
    int x;

    p = (Node *) malloc(sizeof(Node));
    if(p == NULL){
        printf("Memory tidak tersedia\n");
        exit(0);
    }else{
        printf("No\t\t: ");
        scanf("%d", &p->no);
        fflush(stdin);
        printf("Nama\t\t: ");
        gets(p->nama);
        fflush(stdin);
        printf("Nilai\t\t: ");
        scanf("%f", &p->nilai);
        p->next = NULL;
    }
}

// Fungsi untuk menyisipkan node di awal
void awal() {
    if (head != NULL)
        p->next = head;
    head = p;
}

// Fungsi untuk menampilkan isi linked list
void tampil(){
    Node *baca;

    baca = head;
    printf("No\t\tNama\t\tNilai\n");
    while (baca != NULL){   
        printf("%d\t\t", baca->no);
        printf("%s\t\t", baca->nama);
        printf("%.2f\n", baca->nilai);
        baca = baca->next;
    }
}

// Fungsi untuk menyisipkan node di akhir
void akhir() {
    Node *tail;
    if (head == NULL)
        head = p;
    else {
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = p;
    }
}

// Fungsi untuk menyisipkan node setelah node tertentu
void setelah(){
    Node *after;
    int key;

    printf("Disisipkan setelah nomor berapa? ");
    scanf("%d", &key);
    after = head;
    while (after->no != key)
    {
        if(after->next == NULL){
            printf("Nomor tidak ditemukan\n");
            exit(0);
        }
        else
            after = after->next;
    }
    p->next = after->next;
    after->next = p;
}

// Fungsi untuk menyisipkan node sebelum node tertentu
void sebelum(){
    Node *bef, *prevbef;
    int key;

    printf("Disisipkan sebelum nomor berapa? ");
    scanf("%d", &key);
    bef = head;
    while (bef->no != key){
        if(bef->next == NULL){
            printf("Nomor tidak ditemukan\n");
            exit(0);
        }else{
            prevbef = bef;
            bef = bef->next;
        }
    }
    if (bef == head){
        p->next = head;
        head = p; 
    } else {
        p->next = bef;
        prevbef->next = p;
    }
}

// Fungsi untuk memilih metode penyisipan
void kategori(int kategori) {
    switch (kategori) {
    case 1:
        alokasi();
        awal();
        break;
    case 2:
        alokasi();
        akhir();
        break;
    case 3:
        if (head == NULL) {
            printf("SLL masih kosong, tidak dapat menyisipkan data\n\n");
            break;;
        }
        alokasi();
        setelah();
        break;
    case 4:
        if (head == NULL) {
            printf("SLL masih kosong, tidak dapat menyisipkan data\n\n");
            break;;
        }
        alokasi();
        sebelum();
        break;
    default:
        printf("\nPilihan tidak valid\n");
        break;
    }
}

// Fungsi utama
int main() {
    int pilih;

    do {
        printf("\nMenu Insert\n");
        printf("1. Awal\n2. Akhir\n3. After\n4. Before\n5. Keluar\nMasukkan pilihan Anda: ");
        scanf("%d", &pilih);

        if (pilih >= 1 && pilih <= 4)
            kategori(pilih);
        if (head == NULL) {
            continue;
        }else{
            printf("\nData yang ada di dalam SLL:\n");
            tampil();
        }

    } while (pilih != 5);

    return 0;
}
