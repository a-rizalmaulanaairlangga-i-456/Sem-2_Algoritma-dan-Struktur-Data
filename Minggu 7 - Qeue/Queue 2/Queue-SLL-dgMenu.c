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
    int prior;
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
        printf("1. Mengisi Queue\n");
        printf("2. Mengambil isi Queue\n");
        printf("3. Menampilkan isi Queue\n");
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
    int priority;
    printf("Masukkan data yang akan di-Enqueue: ");
    scanf(itemFormat, &input);
    fflush(stdin);
    printf("Nilai prioritasnya: ");
    scanf("%d", &priority);
    fflush(stdin);

    Node *baru = (Node *)malloc(sizeof(Node));
    if (!baru) {
        printf("Memory penuh, data tidak dapat disimpan.\n");
        return;
    }

    baru->data = input;
    baru->prior = priority;
    baru->next = NULL;

    // Jika queue kosong atau prioritas lebih tinggi dari front
    if (q->front == NULL || priority < q->front->prior) {
        baru->next = q->front;
        q->front = baru;
        if (q->rear == NULL) // jika baru pertama insert
            q->rear = baru;
    } else {
        Node *current = q->front;
        // Cari posisi penyisipan
        while (current->next != NULL && current->next->prior <= priority) {
            current = current->next;
        }

        baru->next = current->next;
        current->next = baru;

        if (baru->next == NULL) // jika dimasukkan di akhir
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
        printf(itemFormat "\t %d\n", baca->data, baca->prior);
        baca = baca->next;
    }
    printf("\n");
}
