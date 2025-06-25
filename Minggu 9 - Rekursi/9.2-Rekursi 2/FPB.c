#include <stdio.h>

// Fungsi untuk menghitung FPB
int hitungFPB(int a, int b);

int main() {
    int a, b;
    
    printf("Program FPB antara dua bilangan\n");
    printf("Masukkan dua bilangan: ");
    scanf("%d %d", &a, &b);
    
    int hasil = hitungFPB(a, b);
    printf("FPB dari %d dan %d adalah %d\n", a, b, hasil);
    
    return 0;
}

// Fungsi untuk menghitung FPB
int hitungFPB(int a, int b) {
    if (b == 0) return a;
    else return hitungFPB(b, a % b);
}
