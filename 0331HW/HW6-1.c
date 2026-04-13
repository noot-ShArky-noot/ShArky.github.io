#include <stdio.h>
#include <stdlib.h>

int main(){
    char ch;

    ch = getchar();
    
    if (ch >= '0' && ch <= '9') {
        printf("此字元是數字");
    }
    else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        printf("此字元是英文字母");
    }
    else {
        printf("I don't know what this character is.");
    }
}