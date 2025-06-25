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

        // Fungsi tambahan
// Fungsi untuk mengecek apakah stack penuh
int penuh(stack *);

        // Fungsi khusus
// Fungsi untuk mengecek apakah sebuah kata adalah palindrom
void cek_palindrom(char *);
// Fungsi untuk memilih mode operasi (input integer atau string)
void input_kalimat();

// Fungsi utama main
int main() {
    char jwb;
    printf("Cek kalimat palindrom\n");

    do
    {
        fflush(stdin);
        input_kalimat();
        printf("Mau coba lagi (y/t)? ");
        jwb = getchar();
        fflush(stdin);
    } while (jwb == 'y' || jwb == 'Y');
    

    return 0;
}

// Inisialisasi stack
void inisial(stack *s) {
    s->count = 0;
}

// Menambahkan elemen ke dalam stack
void push(itemType c, stack *s) {
    if (!penuh(s)) {
        s->data[s->count] = c;
        s->count++;
    } else
    puts("Stack penuh, data tidak dapat disimpan.");
}

// Cek apakah stack penuh
int penuh(stack *s) {
    return s->count == MAX;
}

// Fungsi untuk menginputkan kalimat
void input_kalimat() {
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

// Fungsi untuk mengecek apakah sebuah kata adalah palindrom
void cek_palindrom(char *kata) {
    stack s;
    inisial(&s);
    int i, jum = strlen(kata);
    int cek = 1;
    
    for (i = 0; i < jum; i++) {
        push(tolower(kata[i]), &s);  // ubah ke huruf kecil
    }
    
    i = 0;
    do {
        s.count--;
        if (tolower(kata[i]) != s.data[s.count]) {  // bandingkan dalam huruf kecil
            cek = 0;
            break;
        }
        i++;
    } while (i < jum / 2);
    
    if (cek == 0)
        printf("'%s' Bukan palindrom\n\n", kata);
    else
        printf("'%s' adalah palindrom\n\n", kata);
}
