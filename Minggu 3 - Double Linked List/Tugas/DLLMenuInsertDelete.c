#include <stdio.h>
#include <stdlib.h>

// Struktur node double linked list
typedef struct simpul Dnode;
struct simpul {
    int data;
    Dnode *prev, *next;
};

Dnode *head = NULL, *p; // Struktur pointer pendukung umum 
Dnode *bef; // Pointer untuk menyimpan node sebelum node tertentu
Dnode *aft; // Pointer untuk menyimpan node setelah node tertentu
Dnode *hapus;  // Pointer untuk menyimpan node yang akan dihapus

// Fungsi pendukung
void alokasi();
void tampil();
int empty_list();
void bebaskan(Dnode *);
// Fungsi Menu UTama
void menuDLL();

// Fungsi menu insert
void insertMenu();
// Fungsi insert normal
void insert_awal();
void insert_akhir();
// Fungsi menyisipkan data
void insert_after();
void insert_before();

// Fungsi menu delete
void deleteMenu();
// Fungsi delete
void del_awal();
void del_akhir();
void del_tertentu();

// Fungsi utama
int main(){
    int pilihMenu;

    printf("Menu Input dan Delete Double Linked List\n\n");
    do {
        printf("Menu DLL\n1. Insert\n2. Delete\n3. Keluar\nMasukkan pilihan Anda: ");
        scanf("%d", &pilihMenu);
        printf("\n");
        menuSLL(pilihMenu);
        fflush(stdin);

    } while (pilihMenu != 3);

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

// Fungsi insert data di awal list
void insert_awal(){
    alokasi();

    if (head != NULL) {
        p->next = head; // Hubungkan node baru ke node paling awal yang sudah ada
        head->prev = p; // Hubungkan node paling awal ke node baru
    }
    head = p;   // Hubungkan head ke node baru
    fflush(stdin);
    tampil();
}

// Fungsi insert data di akhir list
void insert_akhir(){
    alokasi();

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
    fflush(stdin);
    tampil();
}

// Fungsi untuk menyisipkan data setelah node atau data tertentu
void insert_after(){
    // Kondisi jika list masih kosong
    if (head == NULL) {
        int kondisi;
        kondisi = empty_list();
        if (kondisi == 1) return; // jika user minta kembali ke menu utama
    }
    
    alokasi();
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
    fflush(stdin);
    tampil();
}

// Fungsi untuk menyisipkan data sebelum data tertentu
void insert_before(){
    // Kondisi jika list masih kosong
    if (head == NULL) {
        int kondisi;
        kondisi = empty_list();
        if (kondisi == 1) return; // jika user minta kembali ke menu utama
    }
    
    alokasi();
    int key, stop = 0;

    printf("Disisipkan sebelum node berapa? ");
    scanf("%d", &key);
    bef = head;
    while (bef->data != key && stop != 1) {
        if (bef->next == NULL) {
            printf("%d tidak ada di dalam list\n", key);
            stop = 1;   // Menandakan bahwa data yang dicari tidak ditemukan
        }else
            bef = bef->next;
    }
    if (!stop) {  // Jika data yang dicari ditemukan
        // Menyambungkan data baru ke node sebelumnya dan sesudahnya
        p->next = bef;
        if (bef->prev != NULL) {
            p->prev = bef->prev;
        // Menyambungkan node sebelumnya ke data baru
            bef->prev->next = p;
        }
        // Menyambungkan node sebelumnya ke data baru
        bef->prev = p;

        if (p->prev == NULL) {
            head = p;
        }
        
    }
    fflush(stdin);
    tampil();
}

// Fungsi untuk memilih metode insert
void insertMenu() {
    int pilih;
    printf("Insert Menu\n1. Awal\n2. Akhir\n3. After\n4. Before\nMasukkan pilihan Anda: ");
    scanf("%d", &pilih);

    switch (pilih) {
        case 1:
        insert_awal();
        break;
    case 2:
        insert_akhir();
        break;
    case 3:
        insert_after();
        break;
    case 4:
        insert_before();
        break;
    default:
        printf("\nPilihan tidak valid\n");
        break;
    }
}

// Fungsi untuk membebaskan suatu node
void bebaskan(Dnode *x) {
    free(x);
    x = NULL;
}

// Fungsi menghapus data di urutan awal dalam list
void del_awal(){
    printf("Menghapus data posisi awal....\n");
    hapus = head;
    if(hapus->next == NULL)
        head = NULL;
    else{
        head = hapus->next;
        hapus->next->prev = NULL;
    }
    bebaskan(hapus);
    tampil();
}

// Fungsi untuk menghapus data terakhir dalam list
void del_akhir(){
    printf("Menghapus data posisi akhir....\n");
    hapus = head;
    if(hapus->next == NULL)
        head = NULL;
    else{
        while (hapus->next != NULL)
            hapus = hapus->next;
        hapus->prev->next = NULL;
    }
    bebaskan(hapus);
}

void del_tertentu(){
    int key, stop = 0;

    printf("Data yang ingin dihapus: ");
    scanf("%d", &key);

    hapus = head;
    while (hapus->data != key && stop != 1) {
        if(hapus->next == NULL){
            printf("Data yang ingin dihapus tidak ada di dalam list\n");
            stop = 1;
        }else
            hapus = hapus->next;
    }

    if (!stop)
    {
        if (head->data == key) 
            del_awal();
        else if (hapus->next == NULL)
            del_akhir();
        else{
            hapus->prev->next = hapus->next;
            hapus->next->prev = hapus->prev;
            bebaskan(hapus);
        }
    }
    
}

// Fungsi untuk memilih metode delete
void deleteMenu() {
    // Kondisi jika list masih kosong
    if (head == NULL) {
        int kondisi;
        kondisi = empty_list();
        if (kondisi != 0) return; // jika user minta kembali ke menu utama
    }
    
    int pilih;
    
    printf("Delete Menu\n1. Awal\n2. Akhir\n3. Tertentu\nMasukkan pilihan Anda: ");
    scanf("%d", &pilih);

    switch (pilih) {
    case 1:
        del_awal();
        break;
    case 2:
        del_akhir();
        break;
    case 3:
        del_tertentu();
        break;
    default:
        printf("\nPilihan tidak valid\n");
        break;
    }
}

// Fungsi disaat list data masih kosong
int empty_list(){
    int pilih;
    char kondisi;

    printf("DLL masih kosong, disarankan untuk mengisi data dengan insert awal atau inser akhir terlebih dahulu: \n");
    printf("1. Insert awal\n2. Insert akhir\n3. Kembali\nPilihan anda: ");
    scanf("%d", &pilih);
    switch (pilih) {
    case 1:
        insert_awal();
        printf("\nLanjut ke program sebelumnya? (y/n): ");
        kondisi = getchar();
        break;
    case 2:
        insert_akhir();
        printf("\nLanjut ke program sebelumnya? (y/n): ");
        kondisi = getchar();
        break;
    case 3:
        kondisi = 'n';
        break;
    default:
        printf("Pilihan tidak ada, program dikembalikan ke menu utama.\n");
        kondisi = 'n';
        break;
    }
    fflush(stdin);

    return (kondisi == 'y' || kondisi == 'Y')? 0 : 1;
}

// Fungsi untuk memilih kategori menu SLL
void menuDLL(int pilihan) {
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
