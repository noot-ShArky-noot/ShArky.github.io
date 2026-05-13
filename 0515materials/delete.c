#include <stdio.h>
#include <stdlib.h>

int str_len(char s[]) {
    int i = 0;
    while(s[i] != '\0')
        i++;
    return i;
}

void del(char s1[], char s2[]) {
	int p=search(s1, s2);
	int l=str_len(s2);
	int i=0;

	while((p=search(s1, s2))!=-1) {
		for (i = p; s1[i + l]!='\0'; i++) {
			s1[i] = s1[i + l];
		}
        s1[i] = '\0';
	}
}