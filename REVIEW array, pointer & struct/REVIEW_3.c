#include <stdio.h>

// Struktur data mahasiswa
typedef struct {
    int nrp;
    char nama[100];
    int tugas, uts, uas, nilai_akhir;
    char grade;
} data;

// Fungsi untuk input data mahasiswa
void input(data *input_Mhs, int *n) {
    printf("Berapa jumlah Mahasiswa? ");
    scanf("%d", n);
    getchar();

    printf("\n\n\nMasukkan data Mahasiswa\n\n");
    for (int i = 0; i < *n; i++) {
        printf("Mahasiswa ke-%d\n", i + 1);
        printf("Nama\t\t: ");
        scanf(" %[^\n]", input_Mhs[i].nama);
        getchar();

        printf("NRP\t\t: ");
        scanf("%d", &input_Mhs[i].nrp);
        getchar();

        printf("Nilai Tugas\t: ");
        scanf("%d", &input_Mhs[i].tugas);
        getchar();

        printf("Nilai UTS\t: ");
        scanf("%d", &input_Mhs[i].uts);
        getchar();

        printf("Nilai UAS\t: ");
        scanf("%d", &input_Mhs[i].uas);
        getchar();

        printf("\n");
    }
}

// Fungsi untuk menghitung nilai akhir dan grade
void hitung_grade(data *hitung_grade, int n) {
    for (int i = 0; i < n; i++) {
        hitung_grade[i].nilai_akhir =   (0.2 * hitung_grade[i].tugas) + 
                                        (0.4 * hitung_grade[i].uts) + 
                                        (0.4 * hitung_grade[i].uas);

        // Menentukan grade dengan switch
        switch (hitung_grade[i].nilai_akhir / 10) {
            case 10: 
            case 9:  
            case 8:  
                hitung_grade[i].grade = 'A';
                break;
            case 7:  
                hitung_grade[i].grade = 'B';
                break;
            case 6:  
                hitung_grade[i].grade = 'C';
                break;
            case 5:  
                hitung_grade[i].grade = 'D';
                break;
            default: 
                hitung_grade[i].grade = 'E';
        }
    }
}

// Fungsi untuk menampilkan tabel nilai mahasiswa
void tampil(data *tampil_Data, int n) {
    printf("\n===========================================================================\n");
    printf("\t\tDAFTAR NILAI\n");
    printf("\tMATAKULIAH KONSEP PEMROGRAMAN\n");
    printf("===========================================================================\n");
    printf("No  Nama Mahasiswa       NRP        Tugas  UTS   UAS   Nilai Akhir    Grade\n");
    printf("---------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-3d %-20s %-10d %-6d %-5d %-5d %-14d %c\n", 
               i + 1,   tampil_Data[i].nama, 
                        tampil_Data[i].nrp,
                        tampil_Data[i].tugas, 
                        tampil_Data[i].uts, 
                        tampil_Data[i].uas, 
                        tampil_Data[i].nilai_akhir, 
                        tampil_Data[i].grade);
    }

    printf("---------------------------------------------------------------------------\n");
    printf("Total Mahasiswa = %d\n", n);
}

// Fungsi utama
int main() {
    data Mhs[30];
    int n;

    input(Mhs, &n);
    hitung_grade(Mhs, n);
    tampil(Mhs, n);

    return 0;
}
