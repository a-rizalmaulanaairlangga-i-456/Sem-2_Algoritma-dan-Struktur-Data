#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Fungsi rekursif untuk mengecek bilangan prima
bool isPrima(int n, int pembagi) {
    if (n <= 1) return false; // 0 dan 1 bukan bilangan prima
    if (pembagi > sqrt(n)) return true; // Tidak ditemukan pembagi (tidak bisa di akar sebagai angka bulat) -> prima
    if (n % pembagi == 0) return false; // Ada pembagi -> bukan prima
    return isPrima(n, pembagi + 1); // Lanjut ke pembagi berikutnya
}

int main() {
    int n;
    printf("Cek bilangan prima: \n");
    printf("Masukkan suatu bilangan: ");
    scanf("%d", &n);

    if (isPrima(n, 2))
        printf("%d adalah bilangan prima.\n", n);
    else
        printf("%d bukan bilangan prima.\n", n);

    return 0;
}
