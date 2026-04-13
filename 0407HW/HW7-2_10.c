#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n;
    float sum=0;

    printf("請輸入n值:");
    scanf("%d", &n);
    for (i=1; i<=n; i++) {
        sum=sum+1.0/(float)i;
    }
    printf("總和為:%f", sum);
}