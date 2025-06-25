#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef int TipeData;

// Struktur node pohon biner
typedef struct Node {
    TipeData data;
    struct Node *left, *right;
} Node;

// Fungsi membuat node baru
Node* buatNode(TipeData data) {
    Node* baru = (Node*)malloc(sizeof(Node));
    baru->data = data;
    baru->left = baru->right = NULL;
    return baru;
}

// Fungsi menyisipkan data ke BST
Node* sisip(Node* root, TipeData data) {
    if (root == NULL)
        return buatNode(data);

    if (data < root->data)
        root->left = sisip(root->left, data);
    else if (data > root->data)
        root->right = sisip(root->right, data);
    
    return root;
}

// Traversal inorder
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf(
            #ifdef CHAR_MODE
                "%c ", 
            #else
                "%d ", 
            #endif
            root->data
        );
        inorder(root->right);
    }
}

// Traversal preorder
void preorder(Node* root) {
    if (root != NULL) {
        printf(
            #ifdef CHAR_MODE
                "%c ", 
            #else
                "%d ", 
            #endif
            root->data
        );
        preorder(root->left);
        preorder(root->right);
    }
}

// Traversal postorder
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf(
            #ifdef CHAR_MODE
                "%c ", 
            #else
                "%d ", 
            #endif
            root->data
        );
    }
}

// Cari data dalam BST
Node* cari(Node* root, TipeData key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return cari(root->left, key);
    else
        return cari(root->right, key);
}

// Menu traversal
void menuTraversal(Node* root) {
    int pilihan;
    do {
        printf("\n=== Menu Traversal ===\n");
        printf("1. Inorder\n");
        printf("2. Preorder\n");
        printf("3. Postorder\n");
        printf("4. Kembali ke menu utama\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);
        getchar(); // menangani newline

        switch (pilihan) {
            case 1:
                printf("Traversal Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 2:
                printf("Traversal Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Traversal Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 4:
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 4);
}

// Menu pencarian
void menuPencarian(Node* root) {
    TipeData key;
    printf("Masukkan data yang ingin dicari: ");

    #ifdef CHAR_MODE
        scanf(" %c", &key);
    #else
        scanf("%d", &key);
    #endif

    Node* hasil = cari(root, key);
    if (hasil != NULL)
        printf("Data ditemukan dalam pohon.\n");
    else
        printf("Data tidak ditemukan.\n");
}

// Fungsi untuk membaca input dan membentuk tree
Node* inputData(int n) {
    Node* root = NULL;
    char baris[100];

    printf("Masukkan data (dipisah spasi): ");
    fgets(baris, sizeof(baris), stdin);

    char* token = strtok(baris, " \n");
    while (token != NULL) {
        TipeData data;

        #ifdef CHAR_MODE
            data = token[0]; // Ambil karakter pertama
        #else
            data = atoi(token);
        #endif

        root = sisip(root, data);
        token = strtok(NULL, " \n");
    }

    return root;
}

// Fungsi menu utama
void menu() {
    int jumlah;
    printf("Jumlah Node: ");
    scanf("%d", &jumlah);
    fflush(stdin);
    Node* root = inputData(jumlah);

    int pilihan;
    do {
        printf("\n=== Menu Utama ===\n");
        printf("1. Traversal Pohon\n");
        printf("2. Cari Data\n");
        printf("3. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);
        getchar(); // menangani newline

        switch (pilihan) {
            case 1:
                menuTraversal(root);
                break;
            case 2:
                menuPencarian(root);
                break;
            case 3:
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 3);
}

int main() {
    menu();
    return 0;
}
