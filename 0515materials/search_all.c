#include <stdio.h>
#include <stdlib.h>

int str_len(char s[]) {
    int i=0;

    while(s[i] != '\0')
        i++;

    return i;
}

int search(char s[], char target[], int start) {

    int i, j;

    for(i=start; s[i] != '\0'; i++) {

        j = 0;

        while(target[j] != '\0' && s[i+j] == target[j]) {
            j++;
        }

        if(target[j] == '\0')
            return i;
    }

    return -1;
}

int main() {

    char s[] =
    "I have a cat, you have a cat, and she has a cat.";

    char target[] = "cat";

    int pos = 0;

    while(1) {
        pos = search(s, target, pos);

        if(pos == -1)
            break;

        printf("found at %d\n", pos);

        pos++; // 繼續往後找
    }

    return 0;
}