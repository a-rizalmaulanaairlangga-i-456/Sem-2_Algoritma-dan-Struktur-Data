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

void sebelum(){
    Node *bef, *prevbef;
    int key;

    printf("Disisipkan sebelum nomor berapa? ");
    scanf("%d", &key);
    bef = head;
    while (bef->no != key){
        if(bef->next == NULL){
            printf("Nomor tidak ditemukan\n");
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

    puts("Single Linked List - Insert Awal Data Mahasiswa (dapat melakukan Insert Before)\n");
    do{
        fflush(stdin);
        alokasi();
        awal();
        fflush(stdin);
        printf("Lagi ? (y/n) ");
        jwb = getchar();
        printf("\n\n");
    }while((jwb == 'y') || (jwb == 'Y'));
    fflush(stdin);
    printf("\nIngin menyisipkan data sebelum data tertentu? (y/n) ");
    scanf("%c", &jwb);
    fflush(stdin);
    if(jwb == 'y'){
        fflush(stdin);
        alokasi();
        fflush(stdin);
        sebelum();
        printf("\n\n");
        fflush(stdin);
    }
    printf("Data yang telah diinputkan\n");
    tampil();

    return 0;
}
