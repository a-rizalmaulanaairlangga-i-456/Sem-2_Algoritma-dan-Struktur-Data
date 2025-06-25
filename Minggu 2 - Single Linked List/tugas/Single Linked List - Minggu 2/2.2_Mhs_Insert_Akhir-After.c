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
    printf("No\t\tNama\t\tNilai\n");
    while (baca != NULL){   
        printf("%d\t\t", baca->no);
        printf("%s\t\t", baca->nama);
        printf("%.2f\n", baca->nilai);
        baca = baca->next;
    }
}

void setelah(){
    Node *after;
    int key;

    printf("Disisipkan setelah nomor berapa? ");
    scanf("%d", &key);
    after = head;
    while (after->no != key)
    {
        if(after->next == NULL){
            printf("Nomor tidak ditemukan\n");
            exit(0);
        }
        else
            after = after->next;
    }
    p->next = after->next;
    after->next = p;
}



int main(){
    char jwb;

    puts("Single Linked List - Insert Akhir Data Mahasiswa (dapat melakukan Insert After)\n");
    do{
        fflush(stdin);
        alokasi();
        akhir();
        fflush(stdin);
        printf("Lagi ? (y/n) ");
        jwb = getchar();
        printf("\n\n");
    }while((jwb == 'y') || (jwb == 'Y'));
    fflush(stdin);
    printf("\nIngin menyisipkan data setelah data tertentu? (y/n) ");
    scanf("%c", &jwb);
    fflush(stdin);
    if(jwb == 'y'){
        fflush(stdin);
        alokasi();
        fflush(stdin);
        setelah();
        printf("\n\n");
        fflush(stdin);
    }
    printf("Data yang telah diinputkan\n");
    tampil();

    return 0;
}
