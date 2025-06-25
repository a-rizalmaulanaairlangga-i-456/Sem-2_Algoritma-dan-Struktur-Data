#include <stdio.h>

typedef struct {
    int d, m, y;    
} Date;

int sameDay(Date day1, Date day2) {
    return (day1.d == day2.d && day1.m == day2.m && day1.y == day2.y) ? 1 : 0;
}


int main() {
    Date day1 = {12, 3, 2006}, day2 = {12, 3, 2006};

    if (sameDay(day1, day2)) 
        printf("It is the same day\n");
    else 
        printf("It is not the same day\n");

    return 0;
}

