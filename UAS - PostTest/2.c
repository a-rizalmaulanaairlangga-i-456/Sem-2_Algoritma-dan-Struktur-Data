#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// deklarasi fungsi
void tukar(int *a, int *b);
void quick_sort(int prices[], int kiri, int kanan);
void input_harga(int prices[], int n);
int find_max_book_price(int prices[], int n, int x);
void menu();

// Fungsi main
int main() {
    int prices[MAX];
    int jumlah_data = 0, key;
    find_max_book_price(prices, jumlah_data, key);

    return 0;
}

// Fungsi tukar
void tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi Quick Sort
void quick_sort(int prices[], int kiri, int kanan) {
    if (kiri < kanan) {
        int pivot = prices[kanan];
        int i = kiri - 1;
        for (int j = kiri; j < kanan; j++) {
            if (prices[j] <= pivot) {
                i++;
                tukar(&prices[i], &prices[j]);
            }
        }
        tukar(&prices[i + 1], &prices[kanan]);
        int pivotIndex = i + 1;

        quick_sort(prices, kiri, pivotIndex - 1);
        quick_sort(prices, pivotIndex + 1, kanan);
    }
}

void input_harga(int prices[], int n) {
    printf("Jumlah Buku: ");
    scanf("%d", &n);

    printf("Harga Buku: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }
}

// Binary Search sorted array
int find_max_book_price(int prices[], int n, int x) {
    int pilihan, hasil;
    
    while (1) {+
        printf("\n===== MENU SEARCHING HARGA =====\n");
        printf("1. Input Jumlah dan Harga Buku\n");
        printf("2. Cari Harga Buku Termahal dengan Budget Maksimum\n");
        printf("3. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                input_harga(prices, n);
                break;

            case 2:
                printf("Daftar harga buku sebelum diurutkan:\n");
                for (int i = 0; i < n; i++){
                    printf("%d ", prices[i]);
                }
                printf("\n");
                quick_sort(prices, 0, n - 1);

                printf("Daftar harga buku setelah diurutkan:\n");
                for (int i = 0; i < n; i++){
                    printf("%d ", prices[i]);
                }
                printf("\n-------------------------------------------------------\n");
                printf("Masukkan budget maksimum pelanggan (dalam ribu): ");
                scanf("%d", &x);
                int kiri = 0, kanan = n - 1;
                int temp = -1;

                while (kiri <= kanan) {
                    int tengah = (kiri + kanan) / 2;
                    if (prices[tengah] <= x) 
                        temp = prices[tengah];
                    if (x < prices[tengah]) kanan = tengah - 1;
                    else kiri = tengah + 1;
                }
                if (temp != -1)
                    printf("Harga buku termahal yang bisa dibeli pelanggan : %d\n", temp);
                else
                    printf("Tidak ada harga buku termahal yang bisa dibeli pelanggan. (%d)\n", temp);
                break;

            case 3:
                printf("Keluar dari program.\n");
                return 0;

            default:
                printf("Pilihan tidak valid!\n");
        }
    }
}
