#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;

    do {

        printf("請輸入1~10:");
        scanf("%d", &n);

    } while(n < 1 || n > 10);

    printf("你輸入的是 %d\n", n);

    return 0;
}