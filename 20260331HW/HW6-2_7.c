#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c;

    a= 5;
    b= 6;
    c= 12;

    if ((a+b)<c) {
        printf("This will not make a triangle");
    }
    else {
        printf("This will make a triangle");
    }
}