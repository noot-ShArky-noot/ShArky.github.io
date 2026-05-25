#include <stdio.h>
#include <stdlib.h>
void display(char *ptr, int n);
int main() {
    char *ptr="I play touhou project.";
    display(ptr,8);
}
void display(char *ptr, int n) {
    char *p=ptr;
    p+=(n-1);
    while(*p!='\0') {
        printf("%c", *p);
        p++;
    }
}
/*void display(char *ptr, int n) {
    printf("%s", ptr+n);
}*/