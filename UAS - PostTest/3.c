#include <stdio.h>

void analyze_bst(int arr[], int n);

int main() {
    int jumlah, bst[100];
    analyze_bst(bst, jumlah);
    return 0;
}

void analyze_bst(int arr[], int n) {
    printf("Jumlah Node: ");
    scanf("%d", &n);
    printf("Isi Node: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int root, leaf = 0, heigh = 0, idx = 0, temp = 0, balanced = 0;
    int i = 0, j = 0;
    for(i = 0; i < n; i) {
        if(i == 0) {
            root = arr[i];
            printf("%d\n", root);
            heigh += 1;
        }
        else {
            printf("\n");
            heigh += 1;
        }
        for(j = i + 1; j < n; j++) {
            printf("%d ", arr[j]);
            leaf += 1;
            temp = leaf;
            if(arr[j + 1] < arr[j]) break;
        }
        leaf = 0;
        if(temp % 2 == 0) balanced = 1;
        i = j;
    }
    printf("%d\n", temp);
    printf("%d\n", heigh);
    if(balanced == 1) printf("Balanced");
    else printf("Not Balanced");
}
 