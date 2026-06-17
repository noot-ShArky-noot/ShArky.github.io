#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    FILE *fp=fopen("test.txt", "w");
       while (1) {
        printf("this is practice.");
        break;
    }
    while(fgetc(fp)!=EOF) {
        for (i=0; i<10; i++) {
            printf("test %d", i);
            
        }
    }
}