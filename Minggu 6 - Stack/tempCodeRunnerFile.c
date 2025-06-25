#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int count;
} stack;

            // Deklarasi fungsi
        // Fungsi utama
// Fungsi untuk inisialisasi stack
void inisial(stack *);
// Fungsi untuk menambahkan elemen ke dalam stackint kosong(stack *);
void push(char, stack *);
// Fungsi untuk menghapus elemen dari stack
char pop(stack *);

        // Fungsi tambahan
// Fungsi untuk mengecek apakah stack penuh
int penuh(stack *);
// Fungsi untuk mengecek apakah stack kosong
int kosong(stack *);
// Fungsi untuk mendapatkan data stack paling atas
char lastChar(stack *);

        // Fungsi khusus
// Fungsi untuk menentukan prioritas karakter
int prioritas(char);
// Fungsi untuk mengkonversi string ke dalam postfix
void infixToPostfix(char *, char *);
// Fungsi untuk mengkonversi string ke dalam prefix
void infixToPrefix(char *, char *);
// Fungsi menu antara postfix atau prefix
void menuPilihan();
// Fungsi untuk mengulang proses
void ulangProses(void (*fungsiKonversi)(char *, char *));

int main() {
    menuPilihan();
    return 0;
}

// Fungsi untuk menampilkan menu pilihan
void menuPilihan() {
    char infix[MAX], postfix[MAX], prefix[MAX];
    int pilihan;
    
    printf("Pilih konversi:\n");
    printf("1. Infix ke Postfix\n");
    printf("2. Infix ke Prefix\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan);
    
    if (pilihan == 1) {
        printf("\n\nMENGUBAH NOTASI INFIX MENJADI POSTFIX\n");
        printf("DENGAN MEMANFAATKAN STRUKTUR STACK\n");
        ulangProses(infixToPostfix);
    } else if (pilihan == 2) {
        printf("\n\nMENGUBAH NOTASI INFIX MENJADI PREFIX\n");
        printf("DENGAN MEMANFAATKAN STRUKTUR STACK\n");
        ulangProses(infixToPrefix);
    } else {
        printf("Pilihan tidak valid!\n");
    }
}

// Inisialisasi stack
void inisial(stack *s) {
    s->count = 0;
}

// Mengecek apakah stack kosong
int kosong(stack *s) {
    return s->count == 0;
}

// Mengecek apakah stack penuh
int penuh(stack *s) {
    return s->count == MAX;
}

// Push elemen ke stack
void push(char item, stack *s) {
    if (!penuh(s)) {
        s->data[s->count] = item;
        s->count++;
    }
}

// Pop elemen dari stack
char pop(stack *s) {
    if (!kosong(s)) {
        s->count--;
        return s->data[s->count];
    }
    return '\0';
}

// Melihat elemen di top stack
char lastChar(stack *s) {
    if (!kosong(s)) {
        return s->data[s->count - 1];
    }
    return '\0';
}

// Fungsi untuk menentukan prioritas operator
int prioritas(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

// Fungsi untuk mengulang proses
void ulangProses(void (*fungsiKonversi)(char *, char *)) {
    char infix[MAX], output[MAX], jwb;
    
    do
    {
        fflush(stdin);
        printf("Masukkan ekspresi infix: ");
        scanf("%s", infix);
        
        fungsiKonversi(infix, output); // Memanggil fungsi postfix atau prefix
        
        printf("Hasil konversinya: %s\n", output);

        fflush(stdin);
        printf("Ingin mengulangi proses? (y/n): ");
        jwb = getchar();
        fflush(stdin);
    } while (jwb == 'y' || jwb == 'Y');
    
}

// Konversi infix ke postfix
void infixToPostfix(char *infix, char *postfix) {
    stack s;
    inisial(&s);
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i], &s);
        } else if (infix[i] == ')') {
            while (!kosong(&s) && lastChar(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        } else {
            while (!kosong(&s) && prioritas(lastChar(&s)) >= prioritas(infix[i])) {
                postfix[j++] = pop(&s);
            }
            push(infix[i], &s);
        }
    }
    while (!kosong(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

// Konversi infix ke prefix
void infixToPrefix(char *infix, char *prefix) {
    stack s;
    inisial(&s);
    int i, j = 0;
    int len = strlen(infix);
    char temp[MAX];
    
    // Reverse infix
    for (i = 0; i < len; i++) {
        if (infix[i] == '(') {
            temp[len - i - 1] = ')';
        } else if (infix[i] == ')') {
            temp[len - i - 1] = '(';
        } else {
            temp[len - i - 1] = infix[i];
        }
    }
    temp[len] = '\0';
    
    char postfix[MAX];
    infixToPostfix(temp, postfix);
    
    // Reverse postfix untuk mendapatkan prefix
    len = strlen(postfix);
    for (i = 0; i < len; i++) {
        prefix[i] = postfix[len - i - 1];
    }
    prefix[len] = '\0';
}
