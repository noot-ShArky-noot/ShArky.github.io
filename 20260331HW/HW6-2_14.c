#include <stdio.h>
#include <stdlib.h>

int main() {
    int year;

    scanf("%d", &year);

    if ((year%4000 != 0) && (year%400 == 0)) {
        printf("%d年是閏年", year);
    }
    else if ((year%400 != 0) && (year%100 == 0)) {
        printf("%d年不是閏年", year);
    }
    else if ((year%100 != 0) && (year%4 == 0)) {
        printf("%d年是閏年", year);
    }
    else {
        printf("%d年不是閏年", year);
    }
}