#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a, b, c, sum;

    for (n=100; n<=999; n++) {
        a=n/100;
        b=(n/10)%10;
        c=n%10;

        sum= a*a*a+b*b*b+c*c*c;

        if (sum==n) {
            printf("%d是阿姆斯壯數\n", n);
        }
    }
}