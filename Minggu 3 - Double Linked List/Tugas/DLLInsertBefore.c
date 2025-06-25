#include <stdio.h>
#include <stdlib.h>

// Struktur node double linked list
typedef struct simpul Dnode;
struct simpul {
    int data;
    Dnode *prev, *next;
};

Dnode *head = NULL, *p; // Struktur pointer pendukung umum 
Dnode *bef; // Pointer untuk menyimpan node sebelum node tertentu

// Fungsi pendukung
void alokasi();
void tampil();

// Fungsi insert akhir
void insert_akhir();

// Fungsi menyisipkan data
void insert_before();

// Fungsi utama
int main(){
    char jwb;

    puts("\nDLL Inset Akhir");
    do
    {
        fflush(stdin);
        alokasi();
        insert_akhir();
        fflush(stdin);
        printf("Mau isi lagi? (y/n) ");
        jwb = getchar();
        printf("\n");
    } while ((jwb == 'y') || (jwb == 'Y'));
    tampil();
    fflush(stdin);
    puts("\nInsert Before");
    alokasi();
    fflush(stdin);
    insert_before();
    tampil();

    return 0;
    
}

// Fungsi untuk mengalokasikan atau menambah node baru
void alokasi(){
    int x;

    printf("Data baru yang ingin disimpan: ");
    scanf("%d", &x);

    p = (Dnode *) malloc(sizeof(Dnode));
    if (p == NULL)
    {
        puts("Alokasi memori gagal");
        exit(0);
    }else{
        p->data = x;
        p->next = NULL;
        p->prev = NULL;
    }
    
}

// Fungsi insert data di akhir list
void insert_akhir(){
    Dnode *tail; // Pointer untuk menunjuk node terakhir

    if(head == NULL) // Jika list masih kosong
    head = p; // Hubungkan head ke node baru
    else{ // Jika list sudah tidak kosong
        tail = head; // Pointer tail menunjuk head sebagai awalan
        while (tail->next != NULL) // Cari node terakhir
        tail = tail->next; // Pindah ke node berikutnya
        p->prev = tail; // Hubungkan node baru ke node terakhir (ke belakang)
        tail->next = p; // Hubungkan node terakhir ke node baru (ke depan)
    }
}

// Fungsi untuk menyisipkan data sebelum data tertentu
void insert_before(){
    int key, stop = 0;

    printf("Disisipkan sebelum node berapa? ");
    scanf("%d", &key);
    bef = head;
    while (bef->data != key && stop != 1) {
        if (bef->next == NULL) {
            printf("%d tidak ada di dalam list\n", key);
            stop = 1;   // Menandakan bahwa data yang dicari tidak ditemukan
        }else
            bef = bef->next;
    }
    if (!stop) {  // Jika data yang dicari ditemukan
        // Menyambungkan data baru ke node sebelumnya dan sesudahnya
        p->next = bef;
        if (bef->prev != NULL) {
            p->prev = bef->prev;
        // Menyambungkan node sebelumnya ke data baru
            bef->prev->next = p;
        }
        // Menyambungkan node sebelumnya ke data baru
        bef->prev = p;

        if (p->prev == NULL) {
            head = p;
        }
        
    }
}

// Fungsi untuk menampilkan isi atau data dari Linked List
void tampil(){
    Dnode *baca;

    puts("Isi atau data dari DLL:");
    baca = head;
    while (baca != NULL) {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}

