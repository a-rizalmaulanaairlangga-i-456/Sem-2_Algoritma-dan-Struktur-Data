#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};
Node *head = NULL, *p;

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

void tampil();
void bebaskan(Node *x){
    free(x);
    x = NULL;
}

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

void hapus_tertentu(){
    Node *hapus, *prevHapus;
    int key;

    printf("Data yang mau dihapus ? ");
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
        hapus_tertentu();
    }

    return 0;
}
