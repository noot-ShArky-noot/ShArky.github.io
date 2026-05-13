#include <stdio.h>
#include <stdlib.h>

int str_len(char s[]) {
    int i = 0;
    while(s[i] != '\0')
        i++;
    return i;
}

void replace(char s[], char old[], char newstr[]) {
    int pos = search(s, old);

    if(pos == -1)
        return;

    int lenOld = str_len(old);
    int lenNew = str_len(newstr);
    int lenS = str_len(s);

    for(int i = pos + lenOld; i <= lenS; i++)
        s[i - lenOld + lenNew] = s[i];

    for(int i = 0; i < lenNew; i++)
        s[pos+i] = newstr[i];
}