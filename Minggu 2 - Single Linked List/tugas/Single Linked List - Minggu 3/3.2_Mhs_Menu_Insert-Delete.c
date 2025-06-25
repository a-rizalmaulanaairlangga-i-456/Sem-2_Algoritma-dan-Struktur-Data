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

//                  Deklarasi fungsi pendukung lainnya
// Fungsi pendukung umum
void alokasi();
void tampil();
void bebaskan();

// Fungsi untuk menambahkan node baru
void menuSLL();
void insertMenu();
void awal();
void akhir();
void setelah();
void sebelum();

// Fungsi untuk menghapus node 
void deleteMenu();
void hapus_awal();
void hapus_akhir();
void hapus_tertentu();


// Fungsi utama
int main(){
    int pilihMenu;

    printf("Menu input dan delete data Mahasiswa dalam Single Linked List\n\n");
    do {
        printf("Menu SLL\n1. Insert\n2. Delete\n3. Keluar\nMasukkan pilihan Anda: ");
        scanf("%d", &pilihMenu);
        printf("\n");
        menuSLL(pilihMenu);

    } while (pilihMenu != 3);
    
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

    printf("\n");
    insertMenu();
}

// Fungsi untuk menampilkan data di dalam list
void tampil(){
    Node *baca;

    printf("Data yang telah diinputkan:\n");
    baca = head;
    if (baca == NULL) {
        printf("SLL kosong.\n\n");
        return;
    }

    printf("No\t\tNama\t\tNilai\n");
    while (baca != NULL){   
        printf("%d\t\t", baca->no);
        printf("%s\t\t", baca->nama);
        printf("%.2f\n", baca->nilai);
        baca = baca->next;
    }
    printf("\n");
}

// Fungsi untuk menyisipkan node di awal
void awal() {
    printf("Membentuk Linked List dengan insert di awal\n\n");
    if (head != NULL)
        p->next = head;
    head = p;

    tampil();
}

// Fungsi untuk menambah node di akhir
void akhir(){
    Node *tail;
    printf("Membentuk Linked List dengan insert di akhir\n\n");

    if(head == NULL)
        head = p;
    else{
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = p;
        tail = tail->next;
    }
    tampil();
}

// Fungsi untuk menyisipkan node setelah node tertentu
void setelah(){
    Node *after;
    int key;

    printf("Disisipkan setelah nomor (no) berapa? ");
    scanf("%d", &key);
    after = head;
    while (after->no != key)
    {
        if(after->next == NULL){
            printf("Nomor tidak ditemukan\n");
            return;
        }
        else
            after = after->next;
    }
    printf("Membentuk Linked List dengan insert setelah nomor %d\n\n", key);
    p->next = after->next;
    after->next = p;
    tampil();
}

// Fungsi untuk menyisipkan node sebelum node tertentu
void sebelum(){
    Node *bef, *prevbef;
    int key;

    printf("Disisipkan sebelum nomor (no) berapa? ");
    scanf("%d", &key);
    bef = head;
    while (bef->no != key){
        if(bef->next == NULL){
            printf("Nomor tidak ditemukan\n");
            return;
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
    printf("Membentuk Linked List dengan insert setelah nomor %d\n\n", key);
    tampil();
}

// Fungsi untuk memilih metode insert
void insertMenu() {
    char pilih;
    printf("Insert Menu\na. Insert di awal\nb. Insert di akhir\nc. Insert setelah node (data) tertentu\nd. Insert sebelum node (data) tertentu\nMasukkan pilihan Anda: ");
    scanf(" %c", &pilih);
    fflush(stdin);

    switch (pilih) {
    case 'a':
    case 'A':
        awal();
        break;

    case 'b':
    case 'B':
        akhir();
        break;

    case 'c':
    case 'C':
        if (head == NULL) {
            printf("SLL masih kosong, tidak dapat menyisipkan data\n\n");
            break;;
        }
        setelah();
        break;

    case 'd':
    case 'D':
        if (head == NULL) {
            printf("SLL masih kosong, tidak dapat menyisipkan data\n\n");
            break;;
        }
        sebelum();
        break;

    default:
        printf("\nPilihan tidak valid\n\n");
        break;
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

// Fungsi menghapus data di urutan terakhir dalam list
void hapus_akhir(){
    Node *hapus, *prevHapus;

    printf("Menghapus data posisi akhir\n");
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

// Fungsi untuk memilih metode delete
void deleteMenu() {
    if (head == NULL) 
    {
        printf("Data masih kosong, disarankan untuk menambah data terlebih dahulu\n\n");
        return;
    }
    
    char pilih;
    
    printf("Delete Menu\na. Delete di awal\nb. Delete di akhir\nc. Delete node (data) tertentu\nMasukkan pilihan Anda: ");
    scanf(" %c", &pilih);
    fflush(stdin);

    switch (pilih) {
    case 'a':
    case 'A':
        hapus_awal();
        break;

    case 'b':
    case 'B':
        hapus_akhir();
        break;

    case 'c':
    case 'C':
        hapus_tertentu();
        break;

    default:
        printf("\nPilihan tidak valid\n");
        break;
    }
}

// Fungsi untuk memilih kategori menu SLL
void menuSLL(int pilihan) {
    switch (pilihan) {
        case 1:
            alokasi();
            break;

        case 2:
            deleteMenu();
            break;
            
        case 3:
            break;

        default:
            printf("\nPilihan tidak valid\n");
            break;
    }
}
