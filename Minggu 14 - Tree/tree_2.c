#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

#define MAX 100

// Struktur simpul tree
typedef struct node {
    char data;
    struct node *left, *right;
} Node;

// Stack node untuk menyimpan pointer ke tree
typedef struct {
    Node *data[MAX];
    int top;
} Stack;

// Inisialisasi stack
void initStack(Stack *s) {
    s->top = -1;
}

// Cek apakah stack kosong
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push ke stack
void push(Stack *s, Node *n) {
    if (s->top < MAX - 1)
        s->data[++s->top] = n;
}

// Pop dari stack
Node* pop(Stack *s) {
    if (!isEmpty(s))
        return s->data[s->top--];
    return NULL;
}

// Buat node baru
Node* newNode(char c) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = c;
    n->left = n->right = NULL;
    return n;
}

// Kunjungan preorder
void preorder(Node *root) {
    if (root) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Kunjungan inorder
void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

// Kunjungan postorder
void postorder(Node *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

// Fungsi membentuk tree dari ekspresi infix
Node* buildTreeFromInfix(const char *S) {
    Stack stOperan, stOperator;
    initStack(&stOperan);
    initStack(&stOperator);

    int N = strlen(S);
    for (int i = 0; i < N; i++) {
        char R = S[i];

        if (R == ' ' || R == '\n') continue;

        if (R == '(') {
            push(&stOperator, newNode(R));
        } else if (isdigit(R)) {
            push(&stOperan, newNode(R));
        } else if (R == '+' || R == '-' || R == '*' || R == '/') {
            push(&stOperator, newNode(R));
        } else if (R == ')') {
            Node *op;
            while (!isEmpty(&stOperator) && stOperator.data[stOperator.top]->data != '(') {
                op = pop(&stOperator);
                Node *right = pop(&stOperan);
                Node *left = pop(&stOperan);
                op->left = left;
                op->right = right;
                push(&stOperan, op);
            }
            if (!isEmpty(&stOperator) && stOperator.data[stOperator.top]->data == '(') {
                pop(&stOperator); // pop '('
            }
        }
    }

    // Proses sisa operator
    while (!isEmpty(&stOperator)) {
        Node *op = pop(&stOperator);
        Node *right = pop(&stOperan);
        Node *left = pop(&stOperan);
        op->left = left;
        op->right = right;
        push(&stOperan, op);
    }

    return pop(&stOperan);
}

int main() {
    char S[MAX];
    LARGE_INTEGER start, end, freq;
    double waktu;

    printf("MEMBENTUK BINARY TREE DARI SEBUAH EKSPRESI ARITMATIKA\n");
    printf("DENGAN MEMANFAATKAN STRUKTUR DATA STACK\n\n");

    while (1) {
        printf("\nMasukkan ekspresi dalam notasi infix (atau ketik 'exit' untuk keluar): ");
        fgets(S, sizeof(S), stdin);

        // Hapus newline
        S[strcspn(S, "\n")] = 0;

        if (strcmp(S, "exit") == 0) {
            printf("Terima kasih, program selesai.\n");
            break;
        }

        // mulai waktu komputasi
        QueryPerformanceFrequency(&freq);
        QueryPerformanceCounter(&start);

        Node *root = buildTreeFromInfix(S);

        // selesai waktu komputasi
        QueryPerformanceCounter(&end);
        waktu = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;

        printf("\nHasil kunjungan secara PREORDER adalah : ");
        preorder(root);

        printf("\nHasil kunjungan secara INORDER adalah : ");
        inorder(root);

        printf("\nHasil kunjungan secara POSTORDER adalah : ");
        postorder(root);

        printf("\n\nProcess returned 0 (0x0)   execution time : %.6f s", waktu);
        printf("\nPress any key to continue...\n");
        getchar(); // Pause sejenak
    }

    return 0;
}
