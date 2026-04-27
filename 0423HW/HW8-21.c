#include <stdio.h>
#include <stdlib.h>
int sum2(int);

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", sum2(n));
}

int sum2(int n) {
    if (n==1) {
        return 2;
    }
    return sum2(n-1)+2*n;
}