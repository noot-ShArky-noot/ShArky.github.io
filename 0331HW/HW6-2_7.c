#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c;

    a= 5;
    b= 13;
    c= 12;

    if ((a+b)>c && (b+c)>a && (c+a)>b) {
        printf("This will make a triangle");
    }
    else {
        printf("This will not make a triangle");
    }
}