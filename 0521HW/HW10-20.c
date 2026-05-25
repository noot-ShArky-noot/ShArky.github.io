#include <stdio.h>
#include <stdlib.h>
int length(char*);
int main() {
    int i, total=0;
    char *ptr[3]={"Tom","Lily","James Lee"};
    for(i=0; i<3; i++) {
        puts(ptr[i]);
        total+=length(ptr[i]);
    }
    printf("three strings made up for %d characters",total*sizeof(char));
}
int length(char *ptr) {
    int count=0;
    while(*(ptr+count)!='\0') {
        count++;
    }
    count++;
    return count;
}