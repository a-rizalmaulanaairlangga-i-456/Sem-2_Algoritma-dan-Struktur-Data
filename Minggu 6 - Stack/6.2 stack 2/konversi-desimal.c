#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Struktur stack
typedef int itemType; 
typedef struct {
    itemType data[MAX];
    int count;
} stack;

// Deklarasi fungsi
// Fungsi stack
void inisial(stack *);
int kosong(stack *);
int penuh(stack *);
void push(itemType, stack *);
char pop(stack *);

// Fungsi konversi
void konversiBiner();
void konversiOktal();
void konversiHeksadesimal();

// Fungsi tambahan
void menuPilihan(int);

// Deklarasi pendukung
int MAXSTACK;
int i, n, m, o,p,pilih;
int input;
stack tumpukan;

// Fungsi utama
int main() {
    int desimal;
    printf("Konversi Bilangan Desimal\n");
    printf("Masukkan bilangan desimal yang akan dikonversi: ");
    scanf("%d", &input);
    inisial(&tumpukan);

    menuPilihan(input);
    return 0;
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
void push(itemType item, stack *s) {
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

// Fungsi konversi ke biner
void konversiBiner() {
	for(o=1,n=input;n>0;n=n/2,o++) {
        MAXSTACK=o;
        m=n%2;
        push(m,&tumpukan);
	}
    
    printf("Hasil konversi %d ke Biner = ", input);
    for(i=MAXSTACK;i>0;i--) {
        printf("%d", pop(&tumpukan));
	}
    printf("\n\n");
}

// Fungsi konversi ke oktal
void konversiOktal() {
	for(o=1,n=input;n>0;n=n/8,o++) {
        MAXSTACK=o;
        m=n%8;
        push(m,&tumpukan);
    }
	
    printf("Hasil konversi %d ke Oktal = ", input);
    for(i=MAXSTACK;i>0;i--) {
        printf("%d", pop(&tumpukan));
    }
    printf("\n\n");
}

// Fungsi konversi ke heksadesimal
void konversiHeksadesimal() {
	for(o=1,n=input;n>0;n=n/16,o++) {
        MAXSTACK=o;
        m=n%16;
        push(m,&tumpukan);
	}
	
    printf("Hasil konversi %d ke HeksaDesimal = ", input);
    for(i=MAXSTACK;i>0;i--) {
        p=pop(&tumpukan);
        if(p<=9)
        printf("%d",p);
        else if(p==10)printf("A");
        else if(p==11)printf("B");
        else if(p==12)printf("C");
        else if(p==13)printf("D");
        else if(p==14)printf("E");
        else if(p==15)printf("F");
	}
    printf("\n\n");
}

// Fungsi menu pilihan
void menuPilihan(int input) {
    int pilihan;
    do {
        printf("MENU KONVERSI:\n");
        printf("1. BINER\n");
        printf("2. OKTAL\n");
        printf("3. HEKSADESIMAL\n");
        printf("4. Keluar\n");
        printf("Masukkan pilihan Anda : ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                konversiBiner();
                break;
            case 2:
                konversiOktal();
                break;
            case 3:
                konversiHeksadesimal();
                break;
            case 4:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n\n");
        }
    } while (pilihan != 4);
}
