#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c;

    a= 5;
    b= 13;
    c= 12;

    if ((a+b)>c && (b+c)>a && (c+a)>b) {
        if ((a*a+b*b)==c*c || (b*b+c*c)==a*a || (c*c+a*a)==b*b) {
            printf("直角三角形");
        }
        else if ((a*a+b*b)<c*c || (b*b+c*c)<a*a || (c*c+a*a)<b*b) {
            printf("鈍角三角形");
        }
        else {
            printf("銳角三角形");
        }
    }
    else {
        printf("This will not make a triangle");
    }
}