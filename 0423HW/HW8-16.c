#include <stdio.h>
#include <stdlib.h>
int find_k(int);

int main() {
    int x;
    scanf("%d", &x);
    printf("%d", find_k(x));
}

int find_k(int n) {
    int c0, c1;
    c0=(n-2)/4;
    c1=c0+1;
    if ((n-(4*c0+2))<((4*c1+2)-n)) {
        return c0;
    }
    else {
        return c1;
    }
}