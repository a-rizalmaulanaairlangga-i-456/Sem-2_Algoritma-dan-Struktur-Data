#include <stdio.h>
#include <stdlib.h>

// Fungsi Single Linked list
typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};
Node *head = NULL, *p;

// Deklarasi fungsi pendukung
void alokasi();
void akhir();
void hapus_after();
void tampil();

// Fungsi utama
int main(){
    char jwb;

    puts("Single Linked List - Insert Akhir {dengan Delete Akhir}\n\n");
    do{
        fflush(stdin);
        alokasi();
        akhir();
        fflush(stdin);
        
        printf("Lagi ? (y/n) ");
        jwb = getchar();
    }while((jwb == 'y') || (jwb == 'Y'));

    printf("\n\n");
    tampil();
    while (head != NULL)
    {
        hapus_akhir();
    }

    return 0;
}

// Fungsi alokasi memori untuk Node baru
void alokasi(){
    int x;

    printf("Data yang ingin disimpan: ");
    scanf("%d", &x);

    p = (Node *) malloc(sizeof(Node));
    if(p == NULL){
        printf("Memory tidak tersedia\n");
        exit(0);
    }else{
        p->data = x;
        p->next = NULL;
    }
}

// Fungsi untuk menambahkan node di akhir
void akhir(){
    Node *tail;

    if(head == NULL)
        head = p;
    else{
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = p;
        tail = tail->next;
    }
}

void bebaskan(Node *x){
    free(x);
    x = NULL;
}

// Fungsi menghapus data di urutan akhir list
void hapus_after(){
    Node *hapus, *prevHapus;
    printf("Masukkan ");
    printf("Mulai menghapus data\n");
    hapus = head;
    if(hapus->next == NULL)
        head = NULL;
    else{
        while(hapus->next != NULL){
            prevHapus = hapus;
            hapus = hapus->next;
        }
        prevHapus->next = NULL;
    }
    bebaskan(hapus);
    tampil();
}

// Fungsi menampilkan data
void tampil(){
    Node *baca;

    printf("Isi dari SLL:\n");
    baca = head;
    while (baca != NULL){   
        printf("%d\n", baca->data);
        baca = baca->next;
    }
    if (head == NULL)
    {
        printf("Data kosong\n\n");
    }
    printf("\n");
}