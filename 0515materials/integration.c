#include <stdio.h>
#include <stdlib.h>

double f(double x) {

    return x*x*x + 2*x + 1;
}

int main() {

    double a = 0;      // 下限
    double b = 2;      // 上限

    int n = 100000;    // 切幾份

    double dx = (b-a)/n;

    double area = 0;

    for(int i=0;i<n;i++) {

        double x = a + i*dx;

        area += f(x) * dx;
    }

    printf("積分值 = %lf\n", area);

    return 0;
}