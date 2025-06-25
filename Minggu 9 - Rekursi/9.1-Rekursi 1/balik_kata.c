#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Batas array n
int MAX = 50;

// Fungsi rekursi dari n ke 0
int rekursi(char *, int);

// Fungsi utama
int main() {
    char n[MAX];
    printf("Fungsi rekursi untuk membalikkan kata atau kalimat: \n");
    printf("Masukkan nilai kata atau kalimat: ");
    fgets(n, MAX, stdin);
    n[strcspn(n, "\n")] = 0;

    int len = strlen(n);
    printf("Hasil setelah dibalik: ");
    rekursi(n, len - 1);
}

// Fungsi rekursi
int rekursi(char str[], int index) {
    if (index < 0) 
        return 0;
    
    printf("%c", str[index]);
    rekursi(str, index - 1);
}