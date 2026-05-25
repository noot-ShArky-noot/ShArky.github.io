#include <stdio.h>
#include <stdlib.h>
int str_len(char *s) {
    char *p = s;
    int count = 0;
    while (*p != '\0') {
        count++;
        p++;
    }
    return count;
}
int search(char *s1, char *s2) {
    char *p1, *p2;
    int i = 0;
    if (*s2 == '\0') return 0;
    while (s1[i] != '\0') {
        p1 = s1 + i;
        p2 = s2;
        while (*p1 == *p2 && *p2 != '\0') {
            p1++;
            p2++;
        }
        if (*p2 == '\0') {
            return i; // 找到
        }
        i++;
    }
    return -1;
}
void del(char *s1, char *s2) {
    int p;
    int l = str_len(s2);
    char *start;
    char *src;
    char *dst;

    while ((p = search(s1, s2)) != -1) {
        start = s1 + p;
        dst = start;
        src = start + l;
        while (*src != '\0') {
            *dst = *src;
            dst++;
            src++;
        }
        *dst = '\0';
    }
}
int main() {
    char str[100] = "I am not not not a student";
    char sub[] = "not ";

    del(str, sub);
    printf("%s\n", str);
}