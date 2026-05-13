#include <stdio.h>
#include <stdlib.h>
void reverse(int);

int main() {
    reverse(12345);
}

void reverse(int n) {
    if(n<=0) {
        return;
    }
    else {
        printf("%d", n%10);
        reverse(n/10);
    }
}