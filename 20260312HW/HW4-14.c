// 4-14 B11400002 余承翰
#include <stdio.h>
#include <stdlib.h>

int main() {
    int input;
    printf("請輸入一個十進位數：");
    scanf("%d", &input);
    printf("輸入數字的八進位是：%o\n", input);
    printf("輸入數字的十六進位是：%x\n", input);
    return 0;
}