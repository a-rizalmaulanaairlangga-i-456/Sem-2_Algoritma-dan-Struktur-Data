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

void awal(){
    if(head != NULL)
        p->next = head;
    head = p;
}

void tampil(){
    Node *baca;

    baca = head;
    while (baca != NULL){   
        printf("%d\n", baca->data);
        baca = baca->next;
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

void setelah(){
    Node *after;
    int key;

    printf("Disisipkan setelah node berapa? ");
    scanf("%d", &key);
    after = head;
    while (after->data != key)
    {
        if(after->next == NULL){
            printf("Node tidak ditemukan\n");
            exit(0);
        }
        else
            after = after->next;
    }
    p->next = after->next;
    after->next = p;
}

void sebelum(){
    Node *bef, *prevbef;
    int key;

    printf("Disisipkan sebelum node berapa? ");
    scanf("%d", &key);
    bef = head;
    while (bef->data != key){
        if(bef->next == NULL){
            printf("Node tidak ditemukan\n");
            exit(0);
        }else{
            prevbef = bef;
            bef = bef->next;
        }
    }
    p->next = bef;
    prevbef->next = p;
}

void bebaskan (Node *x){
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

void hapus_akhir(){
    Node *hapus, *prev_hapus;

    hapus = head;
    if(hapus->next == NULL){
        head = NULL;
    }else{
        while(hapus->next != NULL){
            prev_hapus = hapus;
            hapus = hapus->next;
        }
        prev_hapus->next = NULL;
    }
    bebaskan(hapus);
}

void hapus_ttt(){
    Node *hapus, *prev_hapus;
    int key;

    printf("Data yang ingin dihapus: ");
    scanf("%d", &key);
    hapus = head;
    if(hapus->data == key){
        hapus_awal();
    }else{
        while(hapus->data != key){
            if(hapus->next == NULL){
                printf("Data tidak ada\n");
                exit(0);
            }else{
                prev_hapus = hapus;
                hapus = hapus->next;
            }
        }
        prev_hapus->next = hapus->next;
        bebaskan(hapus);
        hapus = NULL;
    }
}


int main(){
    char jwb;
    do{
        fflush(stdin);
        alokasi();
        akhir();
        fflush(stdin);
        printf("Lagi ? (y/n) ");
        jwb = getchar();
    }while((jwb == 'y') || (jwb == 'Y'));
    tampil();
    fflush(stdin);
    puts("Insert before node tertentu");
    alokasi();
    fflush(stdin);
    sebelum();
    tampil();
    // puts("Menghapus node tertentu\n");
    // fflush(stdin);
    // hapus_ttt();
    // tampil();

    return 0;
}
