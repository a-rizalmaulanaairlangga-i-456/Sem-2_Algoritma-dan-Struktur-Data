#include <stdio.h>
#include <stdlib.h>

// Struktur node untuk Single Linked List (SLL)
typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};

// Variabel global
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
int main() {
    int pilihMenu;

    printf("Menu input dan delete Single Linked List\n\n");
    do {
        printf("Menu SLL\n1. Insert\n2. Delete\n3. Keluar\nMasukkan pilihan Anda: ");
        scanf("%d", &pilihMenu);
        printf("\n");
        menuSLL(pilihMenu);

    } while (pilihMenu != 3);

    return 0;
}

// Fungsi untuk mengalokasikan memori untuk node baru
void alokasi() {
    int x;
    printf("Data yang ingin disimpan: ");
    scanf("%d", &x);

    p = (Node *) malloc(sizeof(Node));
    if (p == NULL) {
        printf("Memory tidak tersedia\n");
        exit(0);
    }
    p->data = x;
    p->next = NULL;
}

// Fungsi untuk menampilkan isi linked list
void tampil() {
    Node *baca = head;
    if (baca == NULL) {
        printf("SLL kosong.\n\n");
        return;
    }

    printf("Data dalam SLL\n");
    while (baca != NULL) {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
    printf("\n");
}

// Fungsi untuk menyisipkan node di awal
void awal() {
    if (head != NULL)
        p->next = head;
    head = p;

    tampil();
}

// Fungsi untuk menyisipkan node di akhir
void akhir() {
    Node *tail;
    if (head == NULL)
        head = p;
    else {
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = p;
    }

    tampil();
}

// Fungsi untuk menyisipkan node setelah node tertentu
void setelah() {
    Node *after;
    int key;

    printf("Disisipkan setelah node berapa? ");
    scanf("%d", &key);
    after = head;
    
    while (after != NULL && after->data != key)
        after = after->next;

    if (after == NULL)
        printf("%d tidak ditemukan dalam list\n", key);
    else {
        p->next = after->next;
        after->next = p;
    }

    tampil();
}

// Fungsi untuk menyisipkan node sebelum node tertentu
void sebelum() {
    Node *bef, *prevbef = NULL;
    int key;

    printf("Disisipkan sebelum node berapa? ");
    scanf("%d", &key);

    bef = head;
    while (bef != NULL && bef->data != key) {
        prevbef = bef;
        bef = bef->next;
    }

    if (bef == NULL)
        printf("%d tidak ditemukan dalam list\n", key);
    else if (bef == head) { // Jika menyisipkan sebelum node pertama
        p->next = head;
        head = p;
    } else {
        p->next = bef;
        prevbef->next = p;
    }

    tampil();
}

// Fungsi untuk memilih metode insert
void insertMenu() {
    int pilih;
    printf("Insert Menu\n1. Awal\n2. Akhir\n3. After\n4. Before\nMasukkan pilihan Anda: ");
    scanf("%d", &pilih);

    switch (pilih) {
    case 1:
        alokasi();
        awal();
        break;
    case 2:
        alokasi();
        akhir();
        break;
    case 3:
        if (head == NULL) {
            printf("SLL masih kosong, tidak dapat menyisipkan data\n\n");
            break;;
        }
        alokasi();
        setelah();
        break;
    case 4:
        if (head == NULL) {
            printf("SLL masih kosong, tidak dapat menyisipkan data\n\n");
            break;;
        }
        alokasi();
        sebelum();
        break;
    default:
        printf("\nPilihan tidak valid\n");
        break;
    }
}

// Fungsi untuk membebaskan node
void bebaskan(Node *x){
    free(x);
    x = NULL;
}

// Fungsi menghapus data di urutan awal dalam list
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

// Fungsi menhapus node di posisi tertentu
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
                tampil();
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
    
    int pilih;
    
    printf("Delete Menu\n1. Awal\n2. Akhir\n3. Tertentu\nMasukkan pilihan Anda: ");
    scanf("%d", &pilih);

    switch (pilih) {
    case 1:
        hapus_awal();
        break;
    case 2:
        hapus_akhir();
        break;
    case 3:
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
            insertMenu();
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

