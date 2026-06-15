#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    int fd=open("rand.bin", O_RDWR);
    if (fd<0) return 1;
    
    int max=-1;
    int sum=0;
    int count=0;
    int x;

    while(read(fd, &x, sizeof(int)) == sizeof(int)) {
        printf("%d ", x);
        if (max<x) {
            max=x;
        }
        sum+=x;
        count++;
    }
    close(fd);
    double avg=(double)sum/count;
    printf("max=%d\n", max);
    printf("avg=%.3lf", avg);
}