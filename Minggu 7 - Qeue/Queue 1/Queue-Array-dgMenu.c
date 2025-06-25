#include <stdio.h>
#include <stdlib.h>

// Menentukan batas data
#define MAX 5

// Tipe data untuk elemen stack yang fleksible
typedef char itemType;

// Makro format input: jika itemType diubah, cukup ganti di sini.
#define itemFormat "%c"

// Struktur node untuk stack (SLL)
typedef struct {
    itemType data[MAX];       // Data yang disimpan
    int count,
        front,
        rear;     // Pointer ke node berikutnya
} queue;

        // Fungsi utama queue
// Membuat queue baru
void inisialisasi(queue *);
// Menambahkan elemen ke queue
void enqueue(queue *);
// Menghapus elemen dari queue
itemType dequeue(queue *);
// Cek apakah queue penuh
int isFull(queue *);
// Cek apakah queue kosong
int isEmpty(queue *);
// Menampilkan isi queue
void display(queue *);

// Fungsi menu
void menu();

int main() {
    menu();

    return 0;
}

void inisialisasi(queue *q) {
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}

void enqueue(queue *q) {
    itemType input;

    printf("Data yang mau disimpan: ");
    scanf(itemFormat, &input);
    fflush(stdin);

    if (isFull(q)) {
        puts("Queue penuh, data terakhir tidak bisa masuk\n\n");
    } else {
        q->data[q->rear] = input;
        q->rear = (q->rear + 1) % MAX;
        q->count++;
        printf("\n");
    }
    
}

itemType dequeue(queue *q) {
    itemType temp;

    if (isEmpty(q)) {
        printf("Queue kosong, harap isi Queue terlebih dahulu!\n");

        printf("Mengisi Queue (karena data masih kosong)\n");
        enqueue(q);
        return -1;
    } else {
        temp = q->data[q->front];
        q->front = (q->front + 1) % MAX;
        q->count--;

        return temp;
    }
    
}

int isFull(queue *q) {
    return q->count == MAX;
}

int isEmpty(queue *q) {
    return q->count == 0;
}

void display(queue *q) {
    if (isEmpty(q)) {
        printf("Queue kosong, harap isi Queue terlebih dahulu!\n");

        printf("Mengisi Queue (karena data masih kosong)\n");
        enqueue(q);
        return;
    }

    int index = q->front;
    for (int i = 0; i < q->count; i++) {
        printf(itemFormat " ", q->data[index]);
        index = (index + 1) % MAX;
    }
    printf("\n\n");
}

void menu() {
    int pilihan;
    
    queue antrian;
    itemType temp;
    
    inisialisasi(&antrian);
    
    while(1)
    {
        printf("1. Mengisi Queue (Enqueue - Batas Queue %d)\n", MAX);
        printf("2. Mengambil isi Queue (Dequeue)\n");
        printf("3. Tampilkan isi Queue\n");
        printf("4. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);
        fflush(stdin);

        switch(pilihan) {
            case 1:
                enqueue(&antrian);
                break;
            case 2:
                temp = dequeue(&antrian);
                if (temp != -1)
                    printf("Data yang diambil: " itemFormat "\n\n", temp);
                break;
            case 3:
                display(&antrian);
                break;
            case 4:
                printf("Terima kasih telah menggunakan program ini!\n");
                exit(0);
            default:
                printf("Pilihan tidak tersedia. Silakan pilih kembali!\n");
        }
    }
}