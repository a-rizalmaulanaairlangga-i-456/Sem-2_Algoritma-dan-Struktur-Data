#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define JUMLAH_DATA 100  // jumlah angka yang digenerate otomatis

typedef int tipe_data;  // tipe data yang digunakan

// Struktur node Tree
typedef struct node {
    tipe_data data;
    struct node *left, *right;
} Node;

// Fungsi membuat node baru
Node* buatNode(tipe_data data) {
    Node *baru = (Node*)malloc(sizeof(Node));
    baru->data = data;
    baru->left = baru->right = NULL;
    return baru;
}

// Fungsi menambahkan node ke Tree
Node* tambah(Node* root, tipe_data data) {
    if (root == NULL)
        return buatNode(data);
    if (data < root->data)
        root->left = tambah(root->left, data);
    else if (data > root->data)
        root->right = tambah(root->right, data);
    return root;
}

// Fungsi inorder traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Fungsi preorder traversal
void preorder(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Fungsi postorder traversal
void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Fungsi mencari data dan menampilkan level-nya
int cari(Node* root, tipe_data data, int level) {
    if (root == NULL)
        return 0;
    if (root->data == data) {
        printf("Data %d ditemukan pada level %d\n", data, level);
        return 1;
    }
    else if (data < root->data)
        return cari(root->left, data, level + 1);
    else
        return cari(root->right, data, level + 1);
}

// Fungsi generate angka acak tanpa duplikasi sederhana
void generateData(tipe_data data[], int jumlah) {
    int i, j, angka;
    for (i = 0; i < jumlah;) {
        angka = rand() % 100 + 1;  // nilai antara 1-100
        int duplikat = 0;
        for (j = 0; j < i; j++) {
            if (data[j] == angka) {
                duplikat = 1;
                break;
            }
        }
        if (!duplikat) {
            data[i] = angka;
            i++;
        }
    }
}

// Fungsi Menu Utama
void menu() {
    Node* root = NULL;
    tipe_data data[JUMLAH_DATA];
    srand(time(NULL)); // seed acak

    generateData(data, JUMLAH_DATA);
    printf("Data acak yang dimasukkan: ");
    for (int i = 0; i < JUMLAH_DATA; i++) {
        printf("%d ", data[i]);
        root = tambah(root, data[i]);
    }
    printf("\n");

    int pilihan;
    do {
        printf("\n=== MENU TREE ===\n");
        printf("1. Inorder Traversal\n");
        printf("2. Preorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Cari Data\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 2:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 4: {
                tipe_data cariData;
                printf("Masukkan data yang ingin dicari: ");
                scanf("%d", &cariData);
                if (!cari(root, cariData, 1))
                    printf("Data %d tidak ditemukan dalam Tree\n", cariData);
                break;
            }
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while(pilihan != 0);
}

// Fungsi main
int main() {
    menu();
    return 0;
}
