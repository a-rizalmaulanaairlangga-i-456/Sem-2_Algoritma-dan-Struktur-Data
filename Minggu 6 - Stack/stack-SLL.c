#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struktur node untuk single linked list
typedef char itemType;
typedef struct simpul Node;
struct simpul {
    char data;
    Node *next;
};

Node *head = NULL, *p;

// Deklarasi fungsi
// Fungsi untuk mengalokasikan node baru dalam linked list
void alokasi(char);
// Fungsi untuk menambahkan node di awal linked list
void awal();
// Fungsi untuk mengecek apakah sebuah kata atau kalimat adalah palindrom
void cek_palindrom(char *);

int main() {
    char kata[100];
    printf("Masukkan kata atau kalimat: ");
    fgets(kata, sizeof(kata), stdin); // Menggunakan fgets untuk membaca input termasuk spasi
    kata[strcspn(kata, "\n")] = 0; // Menghapus newline di akhir input
    
    cek_palindrom(kata);
    return 0;
}

// Fungsi untuk mengalokasikan node baru
void alokasi(char x) {
    p = (Node *)malloc(sizeof(Node));
    if (p == NULL) {
        printf("Memory tidak tersedia\n");
        exit(0);
    } else {
        p->data = x;
        p->next = NULL;
    }
}

// Fungsi untuk menambahkan node di awal linked list
void awal() {
    if (head != NULL)
        p->next = head;
    head = p;
}

// Fungsi untuk mengecek apakah sebuah kata atau kalimat adalah palindrom
void cek_palindrom(char *kata) {
    Node *temp;
    int i, jum = strlen(kata);
    int cek = 1;
    
    // Memasukkan karakter ke dalam linked list, mengabaikan spasi dan mengonversi ke huruf kecil
    for (i = 0; i < jum; i++) {
        if (kata[i] != ' ') {
            alokasi(tolower(kata[i]));
            awal();
        }
    }
    
    temp = head;
    i = 0;
    while (temp != NULL) {
        while (kata[i] == ' ') {
            i++;
        }
        
        if (tolower(kata[i]) != temp->data) {
            cek = 0;
            break;
        }
        temp = temp->next;
        i++;
    }
    
    // Menampilkan hasil
    if (cek == 0)
        printf("\nBukan palindrom\n");
    else
        printf("\nPalindrom\n");
}