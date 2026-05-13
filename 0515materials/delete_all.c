#include <stdio.h>
#include <stdlib.h>

int str_len(char s[]) {
    int i=0;

    while(s[i] != '\0')
        i++;

    return i;
}

int search(char s[], char target[], int start) {

    int i,j;

    for(i=start; s[i] != '\0'; i++) {

        j=0;

        while(target[j] != '\0' &&
              s[i+j] == target[j]) {

            j++;
        }

        if(target[j] == '\0')
            return i;
    }

    return -1;
}

void delete_all(char s[], char target[]) {

    int pos;
    int lenT = str_len(target);

    pos = search(s, target, 0);

    while(pos != -1) {

        int i = pos;

        while(s[i + lenT] != '\0') {

            s[i] = s[i + lenT];
            i++;
        }

        s[i] = '\0';

        pos = search(s, target, pos);
    }
}

int main() {

    char s[100] =
    "I have a cat, you have a cat, and she has a cat.";

    delete_all(s, "cat");

    printf("%s\n", s);

    return 0;
}