#include <stdio.h>
#include <string.h>

//struktur data tanggal lahir pegawai
typedef struct tgl_lahir
{
    int bln, tgl, thn;
} TGL_LAHIR;


// Struktur data pegawai
typedef struct data {
    int no_ID;
    char nama[100];
    TGL_LAHIR tgl_Lahir;
    float gaji;
    char jenis_kelamin[10];
} pegawai;

// Fungsi untuk input data pegawai
void input(pegawai *input_Pegawai, int *n) {
    char temp;

    printf("Berapa jumlah Pegawai? ");
    scanf("%d", n);
    getchar();

    printf("\n\nMasukkan data Pegawai\n\n");
    for (int i = 0; i < *n; i++) {
        printf("Data Pegawai ke-%d\n", i + 1);
        printf("Nama\t\t\t: ");
        scanf(" %[^\n]", input_Pegawai[i].nama);
        getchar();

        input_Pegawai[i].no_ID = i + 1;
        printf("Tgl lahir (dd-mm-yyyy)\t: ");
        scanf("%d-%d-%d",   &input_Pegawai[i].tgl_Lahir.tgl, 
                            &input_Pegawai[i].tgl_Lahir.bln, 
                            &input_Pegawai[i].tgl_Lahir.thn);
        getchar();

        printf("Jenis kelamin [L/P]\t: ");
        scanf("%c", &temp);
        getchar();

        if (temp == 'L' || temp == 'l') {
            strcpy(input_Pegawai[i].jenis_kelamin, "Laki-laki");
        } else if (temp == 'P' || temp == 'p') {    
            strcpy(input_Pegawai[i].jenis_kelamin, "Perempuan");
        } else {
            strcpy(input_Pegawai[i].jenis_kelamin, "Jenis kelamin tidak valid");
        }
    
        printf("Gaji/bln\t\t: ");
        scanf("%f", &input_Pegawai[i].gaji);
        getchar();

        printf("\n");
    }
}

// Fungsi untuk menampilkan tabel nilai mahasiswa
void tampil(pegawai *tampil_Data, int n) {
    printf("\n======================================================\n");
    printf("\tData pegawai yang telah diinputkan\n\n");

    for (int i = 0; i < n; i++) {
        printf("No ID\t\t: %d\n", tampil_Data[i].no_ID);
        printf("Nama\t\t: %s\n", tampil_Data[i].nama);
        printf("Tgl lahir\t: %d-%d-%d\n", tampil_Data[i].tgl_Lahir.tgl, tampil_Data[i].tgl_Lahir.bln, tampil_Data[i].tgl_Lahir.thn);
        printf("Jenis kelamin\t: %s\n", tampil_Data[i].jenis_kelamin);
        printf("Gaji/bln\t: Rp %.2f\n\n", tampil_Data[i].gaji);
    }

    printf("------------------------------------------------------\n");
    printf("Total Pegawai = %d\n", n);
}

// Fungsi utama
int main() {
    pegawai Pegawai[30];
    int n;

    input(Pegawai, &n);
    tampil(Pegawai, n);

    return 0;
}
