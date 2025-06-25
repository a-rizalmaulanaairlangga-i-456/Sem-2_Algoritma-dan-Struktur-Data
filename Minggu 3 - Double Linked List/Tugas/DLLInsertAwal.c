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

// Fungsi insert awal
void insert_awal();

// Fungsi utama
int main(){
    char jwb;

    puts("\nDLL Inset Awal");
    do
    {
        fflush(stdin);
        alokasi();
        insert_awal();
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

// Fungsi insert data di awal list
void insert_awal(){
    if (head != NULL) {
        p->next = head; // Hubungkan node baru ke node paling awal yang sudah ada
        head->prev = p; // Hubungkan node paling awal ke node baru
    }
    head = p;   // Hubungkan head ke node baru
    
}
