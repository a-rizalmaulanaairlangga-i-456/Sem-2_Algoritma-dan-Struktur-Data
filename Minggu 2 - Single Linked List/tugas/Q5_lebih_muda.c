#include <stdio.h>

typedef struct {
    int d, m, y;    
} Date;

int isYounger (Date student1, Date student2) {
    if(student1.y > student2.y) return 1;
    else if(student1.y < student2.y) return 0;
    else {
        if(student1.m > student2.m) return 1;
        else if(student1.m < student2.m) return 0;
        else {
            if(student1.d > student2.d) return 1;
            else if(student1.d < student2.d) return 0;
            else printf("Student 1 usianya sama dengan Student 2\n");
        }
    }
}
    

int main() {
    Date student1 = {2, 1, 2008}, student2 = {12, 3, 2006};

    if (isYounger(student1, student2)) 
        printf("Student 1 lebih muda dari Student 2.\n");
    else 
        printf("Student 1 tidak lebih muda dari Student 2\n");

    return 0;
}
