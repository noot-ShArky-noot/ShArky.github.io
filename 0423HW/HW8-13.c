#include <stdio.h>
#include <stdlib.h>
double my_fun(int);
int fac(int);

int main() {
    printf("n=5:%lf n=8:%lf n=10:%lf\n", my_fun(5) \
    , my_fun(8), my_fun(10));
    for (int n=1; ; n++) {
        if ((my_fun(n)-my_fun(n-1))<0.00001) {
            printf("%d", n);
            break;
        }
    }
}

double my_fun(int n) {
    double sum=0;
    for (int i=1; i<=n; i++) {
        sum+=1.0/(float)fac(i);
    }
    return sum;
}

int fac(int n) {
    if (n==0) {
        return 1;
    }
    return n*fac(n-1);
}