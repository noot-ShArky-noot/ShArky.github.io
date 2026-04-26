#include <stdio.h>
#include <stdlib.h>
int prime(long long);

int main() {
    long long int p, m, count=0;
    
    for (p=2; count<8; p++) {
        if (prime(p)) {
            m=(1LL<<p)-1;
            if (prime(m)) {
                printf("%d\n", m);
                count++;
            }
        }
    }
} 

int prime(long long x) {
    long long i;
    for (i=2; i*i<x; i++) {
        if (x%i==0) {
            return 0;
        }
    }
    return 1; //is
}