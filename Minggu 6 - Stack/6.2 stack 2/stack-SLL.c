#include <stdio.h>
#include <stdlib.h>

// Menentukan batas data jika diperlukan (untuk data array jika diperlukan seperti string)
#define MAX 100

// Makro format input: jika itemType diubah, cukup ganti di sini.
#define ITEM_FORMAT "%d"

// Tipe data untuk elemen stack yang fleksible
typedef int itemType;

// Struktur node untuk stack (SLL)
typedef struct simpul stackNode;
typedef struct simpul {
    itemType data;       // Data yang disimpan
    stackNode *next;     // Pointer ke node berikutnya
};

// Inisialisasi top dengan NULL
stackNode *top = NULL;

// Deklarasi fungsi
void push(itemType input);   // Menambahkan elemen ke awal (push)
itemType pop();              // Menghapus elemen dari awal (pop)
int isEmpty();               // Mengecek apakah stack kosong
void printStack();           // Mencetak isi stack
void menu();                 // Fungsi menu pilihan

// Fungsi utama hanya memanggil menu
int main() {
    menu();
    return 0;
}

// Fungsi menu pilihan
void menu() {
    int pilih;
    itemType input;          // Variabel input bertipe itemType
    
    while (1) {
        printf("\nMenu Stack (SLL):\n");
        printf("1. Push (Masukkan data)\n");
        printf("2. Pop (Hapus data)\n");
        printf("3. Tampilkan Stack\n");
        printf("4. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilih);
        
        switch (pilih) {
            case 1:
                printf("Masukkan data yang akan di-push: ");
                scanf(ITEM_FORMAT, &input);
                push(input);
                break;
            case 2:
                if (isEmpty(top)) {
                    printf("Stack kosong!\n");
                } else {
                    input = pop(&top);
                    printf("Nilai yang di-pop: " ITEM_FORMAT "\n", input);
                }
                break;
            case 3:
                printStack(top);
                break;
            case 4:
                printf("Keluar dari program.\n");
                exit(0);
            default:
                printf("Pilihan tidak valid!\n");
        }
    }
}

// Fungsi push: memasukkan elemen ke awal linked list
void push(itemType input) {
    stackNode *newNode = (stackNode *)malloc(sizeof(stackNode));
    if (newNode == NULL) {
        printf("Memory penuh, data tidak dapat disimpan.\n");
        return;
    }
    newNode->data = input;
    newNode->next = top;   // Hubungkan node baru dengan node top saat ini
    top = newNode;         // Jadikan node baru sebagai top
}

// Fungsi pop: menghapus elemen dari awal linked list dan mengembalikan nilainya
itemType pop() {
    if (isEmpty(*top)) {
        printf("Stack kosong!\n");
        return -1; // Nilai error
    }
    stackNode *temp = top;
    itemType popped = temp->data;
    top = temp->next;  // Update top ke node berikutnya
    free(temp);
    return popped;
}

// Fungsi untuk mengecek apakah stack kosong
int isEmpty() {
    return top == NULL;
}

// Fungsi untuk mencetak isi stack
void printStack() {
    if (isEmpty(top)) {
        printf("Stack kosong!\n");
        return;
    }
    
    printf("Isi stack: ");
    stackNode *temp = top;
    while (temp != NULL) {
        printf(ITEM_FORMAT " ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
