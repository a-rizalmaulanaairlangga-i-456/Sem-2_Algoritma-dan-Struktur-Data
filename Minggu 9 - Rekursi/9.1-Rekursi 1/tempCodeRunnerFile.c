#include <stdio.h>
#include <stdlib.h>

// Fungsi rekursi dari 0 ke n
int rekursi(int, int);

// Fungsi utama
int main() {
    int n;
    printf("Fungsi rekursi untuk menampilkan dari 0 sampai n: \n");
    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    rekursi(0, n);
}

// Fungsi rekursi
int rekursi(int i, int n) {
    if (i > n) 
        return 0;
    
    printf("%d ", i);
    rekursi(i + 1, n);
}