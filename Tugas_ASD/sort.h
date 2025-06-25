#ifndef SORTING_LIBRARY_H
#define SORTING_LIBRARY_H

#define ELEMEN_MAKS 100000

void pengurutan_insertion(int data[], int jarak, int jumlah);
void pengurutan_selection(int data[], int jumlah);
void pengurutan_shell(int data[], int jumlah, int jarak[], int jumlah_jarak);
void pengurutan_bubble(int data[], int jarak, int jumlah);
void pengurutan_merge(int data[], int jumlah);
void pembagi_merge(int data[], int kiri, int kanan);
void penggabung_merge(int data[], int kiri, int tengah, int kanan);
void pengurutan_quick(int data[], int jumlah);
void quick_sort(int data[], int kiri, int kanan);
int partition(int data[], int kiri, int kanan);
int indeks_pivot(int kiri, int kanan);
void tukar(int *a, int *b);

#endif
