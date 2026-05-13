#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int count = 0;
    int total = 100000;

    srand(time(NULL));

    for(int i=0;i<total;i++) {

        int d1 = rand()%6 + 1;
        int d2 = rand()%6 + 1;

        if(d1 + d2 == 7)
            count++;
    }

    printf("機率 = %lf\n", (double)count/total);

    return 0;
}