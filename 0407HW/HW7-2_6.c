#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    
    printf("請輸入一個整數: ");
    scanf("%d", &n);

    printf("%d 的因數有: ", n);

    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }

    return 0;
}