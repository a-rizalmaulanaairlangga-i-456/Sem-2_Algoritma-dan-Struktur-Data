#include <stdio.h>
#define M 9999
#define MAX 10

int Q[MAX][MAX], P[MAX][MAX], R[MAX][MAX];
int n;

void inisialisasiStatis() {
    n = 5;
    int dataQ[5][5] = {
        {M, 1, 3, M, M},
        {M, M, 1, M, 5},
        {3, M, M, 2, M},
        {M, M, M, M, 1},
        {M, M, M, M, M}
    };
    int dataP[5][5] = {
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Q[i][j] = dataQ[i][j];
            P[i][j] = dataP[i][j];
            R[i][j] = (dataP[i][j] && dataQ[i][j] != M) ? i : M;
        }
    }
}

void inputDinamis() {
    printf("Masukkan jumlah node: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int input;
                printf("Bobot node %d ke node %d (-1 untuk node tanpa jalur) = ", i + 1, j + 1);
                scanf("%d", &input);
                Q[i][j] = (input == -1) ? M : input;
            } else {
                Q[i][j] = 0; // Jarak ke diri sendiri adalah 0
            }

            P[i][j] = (Q[i][j] == M) ? 0 : 1;
            R[i][j] = (P[i][j]) ? i : M;
        }
    }
}

void warshallBeban() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (Q[i][k] != M && Q[k][j] != M && Q[i][j] > Q[i][k] + Q[k][j]) {
                    Q[i][j] = Q[i][k] + Q[k][j];
                    R[i][j] = R[k][j];
                }
            }
        }
    }
}

void warshallJalur() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                P[i][j] = P[i][j] || (P[i][k] && P[k][j]);
            }
        }
    }
}

void cetakMatriks(int A[MAX][MAX], const char *nama) {
    printf("%s\n", nama);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == M)
                printf("M ");
            else
                printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void cetakRute(int i, int j) {
    if (i == j) {
        return;
    }
    if (R[i][j] == M) {
        return;
    }
    if (R[i][j] == i) {
        printf(" - %d", j + 1);
        return;
    }
    cetakRute(i, R[i][j]);
    cetakRute(R[i][j], j);
}

void tampilkanRute(int asal, int tujuan) {
    if (Q[asal - 1][tujuan - 1] == M) {
        printf("Tidak ada jalur dari %d ke %d.\n", asal, tujuan);
        return;
    }

    printf("Rute terpendek dari %d ke %d: %d", asal, tujuan, asal);
    cetakRute(asal - 1, tujuan - 1);
    printf("\nBeban total: %d\n", Q[asal - 1][tujuan - 1]);
}

int main() {
    int asal, tujuan, pilihan;
    printf("Pilih Mode Graph:\n1. Graph Statis\n2. Graph Dinamis\nPilihan: ");
    scanf("%d", &pilihan);

    if (pilihan == 1) {
        inisialisasiStatis();
    } else if (pilihan == 2) {
        inputDinamis();
    } else {
        printf("Pilihan tidak valid.\n");
        return 0;
    }

    printf("\nMatriks Q-P-R awal\n");
    cetakMatriks(Q, "Matriks Beban (Q)");
    cetakMatriks(P, "Matriks Jalur (P)");
    cetakMatriks(R, "Matriks Rute (R)");

    warshallBeban();
    warshallJalur();

    printf("\nMatriks Q-P-R setelah algoritma Warshall\n");
    cetakMatriks(Q, "Matriks Beban (Q)");
    cetakMatriks(P, "Matriks Jalur (P)");
    cetakMatriks(R, "Matriks Rute (R)");

    printf("Masukkan node asal (1-%d): ", n);
    scanf("%d", &asal);
    printf("Masukkan node tujuan (1-%d): ", n);
    scanf("%d", &tujuan);

    if (asal < 1 || asal > n || tujuan < 1 || tujuan > n) {
        printf("Node asal atau tujuan tidak valid.\n");
    } else {
        tampilkanRute(asal, tujuan);
    }

    return 0;
}