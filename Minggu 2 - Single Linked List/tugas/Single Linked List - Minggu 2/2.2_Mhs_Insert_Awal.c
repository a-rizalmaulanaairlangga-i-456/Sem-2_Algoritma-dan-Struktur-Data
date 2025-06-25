#include <stdio.h>
#include <stdlib.h>

typedef struct siswa Node;
struct siswa {
    int no;
    char nama[20];
    float nilai;
    Node *next;
};
Node *head = NULL, *p;

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

void awal(){
    if(head != NULL)
        p->next = head;
    head = p;
}

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

int main(){
    char jwb;

    puts("Single Linked List - Insert Awal Data Mahasiswa\n");
    do{
        fflush(stdin);
        alokasi();
        awal();
        fflush(stdin);
        printf("Lagi ? (y/n) ");
        jwb = getchar();
        printf("\n\n");
    }while((jwb == 'y') || (jwb == 'Y'));
    printf("Data yang telah diinputkan\n");
    tampil();

    return 0;
}
