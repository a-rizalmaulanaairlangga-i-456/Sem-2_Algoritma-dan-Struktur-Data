#include <stdio.h>
#include <stdlib.h>

// Tipe data fleksibel
typedef char itemType;
#define itemFormat "%c"

// Struktur node
typedef struct simpul Node;
struct simpul {
    itemType data;
    Node *next;
};

// Struktur Queue
typedef struct {
    Node *front, *rear;
    int count;
} queue;

// Deklarasi fungsi
void menu(queue *q);
void inisialisasi(queue *q);
void Enqueue(queue *q);
itemType Dequeue(queue *q);
int isEmpty(queue *q);
void display(queue *q);

// Fungsi utama
int main() {
    queue q;
    inisialisasi(&q);
    menu(&q);
    return 0;
}

// Menu utama
void menu(queue *q) {
    int pilih;
    itemType temp;

    while (1) {
        printf("\nMenu Queue using Single Linked List:\n");
        printf("1. Enqueue (Masukkan data)\n");
        printf("2. Dequeue (Hapus data)\n");
        printf("3. Tampilkan Queue\n");
        printf("4. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilih);
        fflush(stdin);

        switch (pilih) {
            case 1:
                Enqueue(q);
                break;
            case 2:
                temp = Dequeue(q);
                if (temp != -1)
                    printf("Data yang diambil: " itemFormat "\n\n", temp);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Keluar dari program.\n");
                exit(0);
            default:
                printf("Pilihan tidak valid!\n");
        }
    }
}

void inisialisasi(queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
}

// Fungsi untuk Enqueue (insert akhir)
void Enqueue(queue *q) {
    itemType input;
    printf("Masukkan data yang akan di-Enqueue: ");
    scanf(itemFormat, &input);
    fflush(stdin);

    Node *baru = (Node *)malloc(sizeof(Node));
    if (!baru) {
        printf("Memory penuh, data tidak dapat disimpan.\n");
        return;
    }

    baru->data = input;
    baru->next = NULL;

    if (q->front == NULL) {
        q->front = q->rear = baru;
    } else {
        q->rear->next = baru;
        q->rear = baru;
    }

    q->count++;
}

// Fungsi untuk Dequeue (hapus dari depan)
itemType Dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue kosong, tidak bisa melakukan Dequeue!\n");
        printf("Input data ke dalam Queue terlebih dahulu!\n");
        Enqueue(q);
        return -1; // Kode error
    }

    Node *hapus = q->front;
    itemType ambil = hapus->data;

    q->front = q->front->next;
    if (isEmpty(q))
        q->rear = NULL;

    free(hapus);
    q->count--;
    return ambil;
}

// Fungsi mengecek apakah kosong
int isEmpty(queue *q) {
    return q->front == NULL;
}

// Fungsi untuk menampilkan isi Queue
void display(queue *q) {
    if (isEmpty(q)) {
        printf("Queue kosong.\n");
        printf("Input data ke dalam Queue terlebih dahulu!\n");
        Enqueue(q);
        return;
    }

    Node *baca = q->front;
    printf("Isi dari Queue:\n");
    while (baca != NULL) {
        printf(itemFormat " ", baca->data);
        baca = baca->next;
    }
    printf("\n");
}
