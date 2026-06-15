#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>

int main() {
    int arr[]={12,4,5,6};
    int a=12,b=16;

    int fd=open("hw12_12.bin", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd<0)
        return 1;
    
    write(fd, arr, sizeof(arr));
    write(fd, &a, sizeof(a));
    write(fd, &b, sizeof(b));

    close(fd);
    return 0;
}