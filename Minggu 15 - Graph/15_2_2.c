#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define INF 9999

int Q[MAX][MAX], jarak[MAX], dikunjungi[MAX], pred[MAX];

void dijkstra(int asal, int n) {
    int i, j, min, next;

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
    while (top >= 0) printf("%d ", stack[top--]);
    printf("\n");
}

int main() {
    int n, asal, tujuan;
    int i, j;

    printf("Masukkan jumlah node: ");
    scanf("%d", &n);

    printf("Masukkan matriks bobot (%d baris, tiap baris %d angka):\n", n, n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &Q[i][j]);

    printf("Masukkan node asal dan tujuan: ");
    scanf("%d %d", &asal, &tujuan);

    dijkstra(asal, n);

    if (jarak[tujuan] >= INF)
        printf("Tidak ada jalur dari %d ke %d.\n", asal, tujuan);
    else {
        printf("Bobot minimum dari %d ke %d = %d\n", asal, tujuan, jarak[tujuan]);
        cetakRute(tujuan, asal);
    }

    return 0;
}
