#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, P=1;

    printf("請輸入一個數字:");
    scanf("%d", &n);
    for (i=2; i<n; i++) {
        if (n%i==0) {
            P=0;
            break;
        }
    }
    if (P) {
        printf("此數是質數\n");
    }
    else {
        printf("此數不是質數\n");
    }
}