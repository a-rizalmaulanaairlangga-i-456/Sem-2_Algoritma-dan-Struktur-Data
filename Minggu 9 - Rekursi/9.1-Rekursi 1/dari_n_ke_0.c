#include <stdio.h>
#include <stdlib.h>

// Fungsi rekursi dari n ke 0
int rekursi(int);

// Fungsi utama
int main() {
    int n;
    printf("Fungsi rekursi untuk menampilkan dari n sampai 0: \n");
    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    rekursi(n);
}

// Fungsi rekursi
int rekursi(int n) {
    if (n < 0) 
        return 0;
    
    printf("%d ", n);
    rekursi(n - 1);
}