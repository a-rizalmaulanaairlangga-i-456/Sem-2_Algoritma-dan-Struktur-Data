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

void tampil(){
    Node *baca;

    baca = head;
    while (baca != NULL){   
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}

int main(){
    char jwb;

    puts("Single Linked List - Insert Akhir\n\n");
    do{
        fflush(stdin);
        alokasi();
        akhir();
        fflush(stdin);
        printf("Lagi ? (y/n) ");
        jwb = getchar();
    }while((jwb == 'y') || (jwb == 'Y'));
    tampil();

    return 0;
}
