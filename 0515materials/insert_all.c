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

        j = 0;

        while(target[j] != '\0' &&
              s[i+j] == target[j]) {

            j++;
        }

        if(target[j] == '\0')
            return i;
    }

    return -1;
}

void insert(char s[], char t[], int pos) {

    int lenS = str_len(s);
    int lenT = str_len(t);

    // 往右搬
    for(int i=lenS; i>=pos; i--) {

        s[i+lenT] = s[i];
    }

    // 插入
    for(int i=0; i<lenT; i++) {

        s[pos+i] = t[i];
    }
}

void insert_all(char s[],
                char target[],
                char insertStr[]) {

    int pos = 0;

    int lenInsert = str_len(insertStr);
    int lenTarget = str_len(target);

    while(1) {

        pos = search(s, target, pos);

        if(pos == -1)
            break;

        // 在 target 前面插入
        insert(s, insertStr, pos);

        // 跳過：
        // 插入字串 + target
        pos = pos + lenInsert + lenTarget;
    }
}

int main() {

    char s[200] =
    "I have a cat, you have a cat.";

    insert_all(s, "cat", "cute ");

    printf("%s\n", s);

    return 0;
}