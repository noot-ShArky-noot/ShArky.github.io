#include <stdio.h>
#include <stdlib.h>

int length(char *p);
int lengthL(char *p);
int main() {
    char *ptr="We are best friends.";
    printf("total characters:%d\nlower characters:%d", length(ptr), lengthL(ptr));
}
int length(char *p) {
    int count=0;
    char *P=p;
    while(*P!='\0') {
        P++;
        count++;
    }
    return count;
}
int lengthL(char *p) {
    int count=0;
    char *P=p;
    while(*P!='\0') {
        if (*P>='a' && *P<='z') {
            count++;
        }
        P++;
    }
    return count;
}