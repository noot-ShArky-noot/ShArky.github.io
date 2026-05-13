#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;

    scanf("%d", &n);

    switch(n) {

        case 1:
            printf("Monday\n");
            break;

        case 2:
            printf("Tuesday\n");
            break;

        case 3:
            printf("Wednesday\n");
            break;

        default:
            printf("Error\n");
    }

    return 0;
}