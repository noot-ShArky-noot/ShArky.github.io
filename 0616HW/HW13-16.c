#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    if (fp<0) return 1;

    if (argc!=2) {
        printf("wrong usage: enter filename\n");
        return 1;
    }

    fp=fopen(argv[1], "r");
    if(fp==NULL) {
        printf("fail to open file");
    }

    while((ch=fgetc(fp))!=EOF) {
        putchar(ch);
    }
    fclose(fp);
}