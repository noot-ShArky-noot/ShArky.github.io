#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int fd=open("rand.bin", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd<0)
        return 1;
    int i, j; //start writing the file
    for(i=0; i<10; i++) {
        j=rand()%16+1;
        write(fd, &j, sizeof(int));
    }
    close(fd);
}