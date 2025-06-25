#include <stdio.h>
#include <stdlib.h>

// Menentukan batas data
#define MAX 5

// Tipe data untuk elemen stack yang fleksible
typedef int itemType;

// Makro format input: jika itemType diubah, cukup ganti di sini.
#define itemFormat "%d"

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
void enqueue(itemType, queue *);
// Menghapus elemen dari queue
itemType dequeue(queue *);
// Cek apakah queue penuh
int isFull(queue *);
// Cek apakah queue kosong
int isEmpty(queue *);

// Fungsi menu
void menu();

int main() {
}

void inisialisasi(queue *q) {
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}

void enqueue(itemType item, queue *q) {
    if (isFull(q)) {
        puts("Queue penuh, data terakhir tidak bisa masuk\n\n");
    } else {
        q->data[q->rear] = item;
        q->rear = (q->rear + 1) % MAX;
        q->count++;
    }
    
}

itemType dequeue(queue *q) {
    itemType temp;

    if (isEmpty(q)) {
        puts("Queue kosong");
        exit(0);
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

void menu() {
    int pilihan;
    printf("1. Mengisi Queue (Enqueue)\n");
    printf("2. Mengambil isi Queue (Dequeue)\n");
    printf("3. Tampilkan isi Queue\n");
    printf("4. Keluar\n");
    printf("Masukkan pilihan Anda:");
    scanf("%d", &pilihan);

    queue antrian;
    char jwb;
    itemType temp, input;

    inisialisasi(&antrian);

    do
    {
        fflush(stdin);
        
        printf("Data yang mau disimpan:");
        scanf(itemFormat, &input);
        fflush(stdin);

        enqueue(input, &antrian);
        
        printf("Lagi (y/t)? ");
        jwb = getchar();
        
        fflush(stdin);
    } while (jwb == 'y' || jwb == 'Y');
    
    for (int i = 0; i < MAX; i++) {
        temp = dequeue(&antrian);
        printf(itemFormat " ", temp);
    }
    

}