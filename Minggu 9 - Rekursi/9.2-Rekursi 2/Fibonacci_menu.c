#include <stdio.h>

// Fungsi deklarasi
void fibonacci_iterasi(int batas, int a, int b);
void fibonacci_rekursi(int batas, int a, int b, int count);

int main() {
    int pilihan, n;

    while (1) {
        // Tampilkan menu
        printf("\nMenu Program Deret Fibonacci:\n");
        printf("1. Tampilkan Fibonacci dengan Iterasi\n");
        printf("2. Tampilkan Fibonacci dengan Rekursi\n");
        printf("3. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        // Proses pilihan
        switch (pilihan) {
            case 1:
                printf("Masukkan jumlah angka Fibonacci yang ingin ditampilkan: ");
                scanf("%d", &n);
                printf("Deret Fibonacci (Iterasi): ");
                fibonacci_iterasi(n, 0, 1);
                printf("\n");
                break;

            case 2:
                printf("Masukkan jumlah angka Fibonacci yang ingin ditampilkan: ");
                scanf("%d", &n);
                printf("Deret Fibonacci (Rekursi): ");
                if (n >= 1) printf("0 ");
                if (n >= 2) printf("1 ");
                if (n >= 3) fibonacci_rekursi(n, 0, 1, 2);
                printf("\n");
                break;

            case 3:
                printf("Terima kasih!\n");
                return 0;

            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }

    return 0;
}

// Fungsi iteratif untuk mencetak deret Fibonacci
void fibonacci_iterasi(int batas, int a, int b) {
    if (batas >= 1) printf("0 ");
    if (batas >= 2) printf("1 ");

    for(int i = 2; i < batas; i++) {
        printf("%d ", b = a + b);
        a = b - a;
    }
}

// Fungsi rekursif untuk mencetak deret Fibonacci
void fibonacci_rekursi(int batas, int a, int b, int count) {
    if (count >= batas) return;
    printf("%d ", a + b);
    fibonacci_rekursi(batas, b, a + b, count + 1);
}
