#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Menentukan batas data array
#define MAX 100

// Ubah ke int menyimpan integer
// Ubah ke char menyimpan string
typedef int itemType; 

typedef struct {
    itemType data[MAX];
    int count;
} stack;

            // Deklarasi fungsi
        // Fungsi utama
// Fungsi untuk inisialisasi stack
void inisial(stack *);
// Fungsi untuk menambahkan elemen ke dalam stack
void push(itemType, stack *);
// Fungsi untuk menghapus elemen dari stack
itemType pop(stack *s);

        // Fungsi tambahan
// Fungsi untuk mengecek apakah stack penuh
int penuh(stack *);
// Fungsi untuk mengecek apakah stack kosong
int kosong(stack *);
// Fungsi untuk menampilkan isi stack
void tampilkanStack(stack *);

        // Fungsi khusus
// Fungsi untuk mengecek apakah sebuah kata adalah palindrom
void cek_palindrom(char *);
// Fungsi untuk mengecek tipe itemType
void cek_tipe_data();
// Fungsi menu untuk stack integer
void menuStack();
// Fungsi untuk memilih mode operasi (input integer atau string)
void pilih_mode();

// Fungsi utama main
int main() {
    pilih_mode();

    return 0;
}

// Fungsi untuk memilih mode operasi
void pilih_mode() {
    int pilihan;
    do {
        printf("\nPilih mode:\n");
        printf("1. Input data integer (Stack)\n");
        printf("2. Cek Palindrom\n");
        printf("3. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);
        getchar(); // Membersihkan newline

        cek_tipe_data(); // Cek apakah itemType sesuai

        switch (pilihan) {
            case 1:
                menuStack();
                break;
            case 2:
                if (sizeof(itemType) != sizeof(char)) {
                    printf("\nTipe itemType bukan char! Harap ubah ke char untuk cek palindrom.\n");
                } else {
                    char kata[MAX];
                    printf("Masukkan kata atau kalimat: ");
                    fgets(kata, MAX, stdin);
                    // Menghapus karakter newline jika ada
                    size_t len = strlen(kata);
                    if (len > 0 && kata[len - 1] == '\n') {
                        kata[len - 1] = '\0';
                    }
                    cek_palindrom(kata);
                }
                break;
            case 3:
                printf("\nProgram selesai.\n");
                break;
            default:
                printf("\nPilihan tidak valid! Coba lagi.\n");
        }
    } while (pilihan != 3);
}

// Inisialisasi stack
void inisial(stack *s) {
    s->count = 0;
}

// Cek apakah stack penuh
int penuh(stack *s) {
    return s->count == MAX;
}

// Cek apakah stack kosong
int kosong(stack *s) {
    return s->count == 0;
}

// Menambahkan elemen ke dalam stack
void push(itemType c, stack *s) {
    if (!penuh(s)) {
        s->data[s->count] = c;
        s->count++;
    } else
        puts("Stack penuh, data tidak dapat disimpan.");
}

// Menghapus elemen dari stack
itemType pop(stack *s) {
    if (!kosong(s)) {
        s->count--;
        return s->data[s->count];
    }
    puts("Stack Kosong, tidak dapat mengambil data");
    return 0; // Mengembalikan 0 jika stack kosong
}

// Fungsi untuk menampilkan isi stack
void tampilkanStack(stack *s) {
    if (kosong(s)) {
        printf("Stack kosong.\n");
    } else {
        printf("Isi stack: \n");
        for (int i = s->count - 1; i >= 0; i--) {
            printf("%d\n", s->data[i]);
        }
        printf("\n");
    }
}

// Fungsi untuk mengecek apakah sebuah kata adalah palindrom
void cek_palindrom(char *kata) {
    stack s;
    inisial(&s);
    int i, jum = strlen(kata);
    int cek = 1;
    
    for (i = 0; i < jum; i++) {
        push(kata[i], &s);
    }
    
    i = 0;
    do {
        s.count--;
        if (kata[i] != s.data[s.count]) {
            cek = 0;
            break;
        }
        i++;
    } while (i < jum / 2);
    
    if (cek == 0)
        printf("\nBukan kata palindrom\n");
    else
        printf("\nKata adalah palindrom\n");
}

// Fungsi untuk mengecek tipe itemType
void cek_tipe_data() {
    if (sizeof(itemType) == sizeof(char)) {
        printf("\nitemType bertipe char\n");
    } else if (sizeof(itemType) == sizeof(int)) {
        printf("\nitemType bertipe integer\n");
    } else {
        printf("\nitemType memiliki tipe lain\n");
    }
}

// Fungsi menu untuk stack integer
void menuStack() {
    stack s;
    inisial(&s);
    int pilihan, angka;
    do {
        printf("\nMENU STACK using ARRAY :\n");
        printf("1. Mengisi Stack (PUSH)\n");
        printf("2. Mengambil isi Stack (POP)\n");
        printf("3. Menampilkan isi Stack\n");
        printf("4. Keluar\n");
        printf("Masukkan pilihan anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan angka: ");
                scanf("%d", &angka);
                push(angka, &s);
                break;
            case 2:
                if (!kosong(&s)) {
                    printf("Data diambil: %d\n", pop(&s));
                } else {
                    printf("Stack kosong!\n");
                }
                break;
            case 3:
                tampilkanStack(&s);
                break;
            case 4:
                printf("Keluar dari menu stack.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 4);
}
