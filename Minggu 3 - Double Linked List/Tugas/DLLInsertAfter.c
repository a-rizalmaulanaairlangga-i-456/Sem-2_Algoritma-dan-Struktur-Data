#include <stdio.h>
#include <stdlib.h>

// Struktur node double linked list
typedef struct simpul Dnode;
struct simpul {
    int data;
    Dnode *prev, *next;
};

Dnode *head = NULL, *p; // Struktur pointer pendukung umum 
Dnode *aft; // Pointer untuk menyimpan node setelah node tertentu

// Fungsi pendukung
void alokasi();
void tampil();

// Fungsi insert akhir
void insert_akhir();

// Fungsi menyisipkan data
void insert_after();

// Fungsi utama
int main(){
    char jwb;

    puts("\nDLL Inset Akhir");
    do
    {
        fflush(stdin);
        alokasi();
        insert_akhir();
        fflush(stdin);
        printf("Mau isi lagi? (y/n) ");
        jwb = getchar();
        printf("\n");
    } while ((jwb == 'y') || (jwb == 'Y'));
    tampil();
    fflush(stdin);
    puts("\nInsert After");
    alokasi();
    fflush(stdin);
    insert_after();
    tampil();

    return 0;
    
}

// Fungsi untuk mengalokasikan atau menambah node baru
void alokasi(){
    int x;

    printf("Data baru yang ingin disimpan: ");
    scanf("%d", &x);

    p = (Dnode *) malloc(sizeof(Dnode));
    if (p == NULL)
    {
        puts("Alokasi memori gagal");
        exit(0);
    }else{
        p->data = x;
        p->next = NULL;
        p->prev = NULL;
    }
    
}

// Fungsi insert data di akhir list
void insert_akhir(){
    Dnode *tail; // Pointer untuk menunjuk node terakhir

    if(head == NULL) // Jika list masih kosong
    head = p; // Hubungkan head ke node baru
    else{ // Jika list sudah tidak kosong
        tail = head; // Pointer tail menunjuk head sebagai awalan
        while (tail->next != NULL) // Cari node terakhir
        tail = tail->next; // Pindah ke node berikutnya
        p->prev = tail; // Hubungkan node baru ke node terakhir (ke belakang)
        tail->next = p; // Hubungkan node terakhir ke node baru (ke depan)
    }
}

// Fungsi untuk menyisipkan data setelah node atau data tertentu
void insert_after(){
    int key, stop = 0;  // Menyimpan data yang ingin dicari dan menentukan pengkondisian apakah data sudah ditemukan atau belum
    
    printf("Sisipkan data baru setelah node berapa? ");
    scanf("%d", &key);
    
    aft = head; // Pointer untuk menunjuk node awal list
    while (aft->data != key && stop != 1) {  // Cari node yang data-nya sesuai dengan key
        if(aft->next == NULL){  // Jika node yang dicari tidak ditemukan
            printf("Data yang dicari tidak ada di dalam list\n");
            stop = 1;   // Menandakan bahwa data yang dicari tidak ditemukan
        }else
            aft = aft->next; // Pindah ke node berikutnya
        }
        
        
    if (!stop) {  // Jika data yang dicari ditemukan
        // Menyambungkan data baru ke node sebelumnya dan sesudahnya
        p->prev = aft;
        if (aft->next != NULL) { 
            p->next = aft->next;    // Jika node yang dicari bukan node terakhir
        
        // Menyambungkan node sesudahnya ke data baru
            aft->next->prev = p;    // Jika node yang dicari adalah node terakhir jelas tidak ada node lagi (next), apalagi ada pointer prev
        }
        // Menyambungkan node sebelumnya ke data baru
        aft->next = p;
    }
    
    
}

// Fungsi untuk menampilkan isi atau data dari Linked List
void tampil(){
    Dnode *baca;

    puts("Isi atau data dari DLL:");
    baca = head;
    while (baca != NULL) {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}

