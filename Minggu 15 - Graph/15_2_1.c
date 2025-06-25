#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 999

int Q[MAX][MAX];  // Matriks bobot
int jarak[MAX];   // Beban minimum
int dikunjungi[MAX]; // Penanda node yang sudah dikunjungi
int pred[MAX];    // Menyimpan rute

void dijkstra(int asal, int n) {
    int i, j, min, next;

    // Inisialisasi
    for (i = 1; i <= n; i++) {
        jarak[i] = Q[asal][i];
        pred[i] = asal;
        dikunjungi[i] = 0;
    }

    dikunjungi[asal] = 1;

    for (i = 1; i < n; i++) {
        min = INF;
        for (j = 1; j <= n; j++) {
            if (!dikunjungi[j] && jarak[j] < min) {
                min = jarak[j];
                next = j;
            }
        }

        dikunjungi[next] = 1;

        for (j = 1; j <= n; j++) {
            if (!dikunjungi[j]) {
                if (min + Q[next][j] < jarak[j]) {
                    jarak[j] = min + Q[next][j];
                    pred[j] = next;
                }
            }
        }
    }
}

void cetakRute(int tujuan, int asal) {
    int stack[MAX], top = -1, i = tujuan;

    while (i != asal) {
        stack[++top] = i;
        i = pred[i];
    }

    stack[++top] = asal;

    printf("Rute terpendek: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int n = 5;
    int asal, tujuan;
    int i, j;

    // Inisialisasi matriks Q dengan INF
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            Q[i][j] = (i == j) ? 0 : INF;

    // Graph berdasarkan gambar
    Q[1][2] = 1;
    Q[1][3] = 3;
    Q[2][3] = 1;
    Q[2][5] = 5;
    Q[3][1] = 3;
    Q[3][4] = 2;
    Q[4][5] = 1;

    printf("Masukkan node asal (1-5): ");
    scanf("%d", &asal);
    printf("Masukkan node tujuan (1-5): ");
    scanf("%d", &tujuan);

    dijkstra(asal, n);

    printf("Bobot minimum dari %d ke %d = %d\n", asal, tujuan, jarak[tujuan]);
    cetakRute(tujuan, asal);

    return 0;
}
