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

void replace_all(char s[], char old[], char newstr[]) {

    int lenOld = str_len(old);
    int lenNew = str_len(newstr);

    int pos = search(s, old, 0);

    while(pos != -1) {

        int lenS = str_len(s);

        // 挪動空間
        for(int i=lenS; i>=pos+lenOld; i--) {

            s[i - lenOld + lenNew] = s[i];
        }

        // 複製新字串
        for(int i=0;i<lenNew;i++) {

            s[pos+i] = newstr[i];
        }

        pos = search(s, old, pos + lenNew);
    }
}

int main() {

    char s[200] =
    "I have a cat, you have a cat, and she has a cat.";

    replace_all(s, "cat", "dog");

    printf("%s\n", s);

    return 0;
}