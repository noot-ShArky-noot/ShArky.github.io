#include <stdio.h>
#include <stdlib.h>

int str_len(char s[]) {
    int i = 0;
    while(s[i] != '\0')
        i++;
    return i;
}

void insert(char s[], char t[], int pos) {
    int lenS = str_len(s);
    int lenT = str_len(t);

    for(int i = lenS; i >= pos; i--)
        s[i+lenT] = s[i];

    for(int i = 0; i < lenT; i++)
        s[pos+i] = t[i];
}