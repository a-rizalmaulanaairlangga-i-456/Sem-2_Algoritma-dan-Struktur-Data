#include <stdio.h>

// Fungsi untuk menampilkan deret fibonacci
void fibonacci(int batas, int a, int b);

int main() {
    int input;
    
    printf("Program menampilkan deret Fibonacci sebanyak input dengan fungsi iterasi\n");
    printf("Masukkan jumlah angka Fibonacci yang ingin ditampilkan: ");
    scanf("%d", &input);
    
    // Cetak angka pertama
    printf("Deret Fibonacci: ");
    if (input >= 1)
        printf("0 ");
    if (input >= 2)
        printf("1 ");

    // Memulai dari angka ke-3 jika input >= 3
    fibonacci(input, 0, 1);

    return 0;
}

// Fungsi iterasi untuk mencetak deret Fibonacci
void fibonacci(int batas, int a, int b) {
    for(int i = 2; i < batas; i++) {
        printf("%d ", b = a + b);
        a = b - a;
    }
}
