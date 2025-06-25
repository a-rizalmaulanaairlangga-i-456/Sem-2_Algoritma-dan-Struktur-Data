#include <stdio.h>
#include <stdlib.h>

// Fungsi Single Linked List
typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};
Node *head = NULL, *p;

// Fungsi pendukung lainnya
void alokasi();
void akhir();
void hapus_awal();
void tampil();

// Fungsi utama
int main(){
    char jwb;

    puts("Single Linked List - Insert Akhir {dengan Delete Awal}\n\n");
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
        hapus_awal();
    }

    return 0;
}

// Fungsi alokasi node baru
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

// Fungsi untuk menambah node di akhir
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

// Fungsi untuk membebaskan suatu node
void bebaskan(Node *x){
    free(x);
    x = NULL;
}

// Fungsi untuk menghapus node di urutan awal
void hapus_awal(){
    Node *hapus;

    printf("Menghapus data posisi awal\n");
    hapus = head;
    if(hapus->next == NULL)
        head = NULL;
    else{
        head = hapus->next;
        bebaskan(hapus);
    }
    tampil();
}

// Fungsi untuk menampilkan data di dalam list
void tampil(){
    Node *baca;

    printf("Isi dari SLL:\n");
    baca = head;
    while (baca != NULL){   
        printf("%d\n", baca->data);
        baca = baca->next;
    }
        if (head == NULL)
    printf("Data kosong\n\n");

    printf("\n");
}
