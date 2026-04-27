#include <stdio.h>
#include <stdlib.h>
int rsum(int);

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", rsum(n));
}

int rsum(int n) {
    if (n==2) {
        return 2;
    }
    return n*(n-1)+rsum(n-1);
}