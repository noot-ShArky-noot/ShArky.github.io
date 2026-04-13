#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float a=1, b=1, c=-6;
    double x1, x2;

    if ((b*b-4*a*c)>0) {
        x1=(-b+sqrt(b*b-4*a*c))/(a*2);
        x2=(-b-sqrt(b*b-4*a*c))/(a*2);
        printf("x1=%lf, x2=%lf", x1, x2);
    }
    else if ((b*b-4*a*c)==0) {
        x1=-b/2*a;
        x2=x1;
        printf("x1=%lf, x2=%lf", x1, x2);
    }
    else {
        printf("沒有實根");
    }
}