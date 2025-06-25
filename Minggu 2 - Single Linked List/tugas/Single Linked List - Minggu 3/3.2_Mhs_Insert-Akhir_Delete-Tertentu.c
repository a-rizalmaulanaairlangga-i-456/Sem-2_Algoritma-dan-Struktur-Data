#include <stdio.h>
#include <stdlib.h>

// Fungsi Single Linked List
typedef struct siswa Node;
struct siswa {
    int no;
    char nama[20];
    float nilai;
    Node *next;
};
Node *head = NULL, *p;

// Fungsi pendukung lainnya
void alokasi();
void akhir();
void hapus_awal();
void hapus_tertentu();
void tampil();


// Fungsi utama
int main(){
    char jwb;

    puts("Single Linked List - Insert Akhir Data Mahasiswa - Delete Tertentu\n");
    do{
        fflush(stdin);
        alokasi();
        akhir();
        fflush(stdin);
        printf("Lagi ? (y/n) ");
        jwb = getchar();
        printf("\n");
    }while((jwb == 'y') || (jwb == 'Y'));
    tampil();
    fflush(stdin);
    printf("Ingin menghapus data tertentu ? (y/n) ");
    jwb = getchar();
    fflush(stdin);
    printf("\n");
    if (jwb == 'y' || jwb == 'Y')
    {
        hapus_tertentu();
    }
    
    return 0;
}

// Fungsi alokasi node baru
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
}

// Fungsi menghapus data tertentu di dalam list
void hapus_tertentu(){
    Node *hapus, *prevHapus;
    int key;

    printf("Data yang mau dihapus ? ");
    scanf("%d", &key);
    hapus = head;
    if(hapus->no == key)
        hapus_awal();
    else{
        while (hapus->no != key){
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

// Fungsi untuk menampilkan data di dalam list
void tampil(){
    Node *baca;

    printf("Isi dari SLL:\n");
    baca = head;
    printf("No\t\tNama\t\tNilai\n");
    while (baca != NULL){   
        printf("%d\t\t", baca->no);
        printf("%s\t\t", baca->nama);
        printf("%.2f\n", baca->nilai);
        baca = baca->next;
    }
}

