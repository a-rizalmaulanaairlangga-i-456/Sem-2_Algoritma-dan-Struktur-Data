#include <stdio.h>
#include <stdlib.h>

// Struktur node double linked list
typedef struct simpul Dnode;
struct simpul {
    int data;
    Dnode *prev, *next;
};

Dnode *head = NULL, *p; // Struktur pointer pendukung umum 

// Fungsi pendukung
void alokasi();
void tampil();

// Fungsi insert akhir
void insert_akhir();

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
