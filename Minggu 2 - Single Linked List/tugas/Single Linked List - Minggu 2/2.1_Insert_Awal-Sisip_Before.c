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
    
    if (bef == head){
        p->next = head;
        head = p; 
    } else {
        p->next = bef;
        prevbef->next = p;
    }
}

int main(){
    char jwb;

    puts("Single Linked List - Insert Before\n\n");
    do{
        fflush(stdin);
        alokasi();
        awal();
        fflush(stdin);
        printf("Lagi ? (y/n) ");
        jwb = getchar();
    }while((jwb == 'y') || (jwb == 'Y'));
    tampil();
    fflush(stdin);
    puts("\nInsert Before node tertentu");
    alokasi();
    fflush(stdin);
    sebelum();
    tampil();

    return 0;
}
