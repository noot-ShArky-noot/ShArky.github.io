#include <stdio.h>
#include <stdlib.h>

int str_len(char s[]) {
    int i = 0;
    while(s[i] != '\0')
        i++;
    return i;
}

int search(char s[], char target[]) {
    int i, j;

    for(i = 0; s[i] != '\0'; i++) {
        j = 0;

        while(target[j] != '\0' && s[i+j] == target[j])
            j++;

        if(target[j] == '\0')
            return i;
    }

    return -1;
}