/*B11400002 余承翰 作業4-10 加減乘除取餘數*/
#include <stdio.h>
#include <stdlib.h>
// #include <windows.h>

int main() {
    // SetConsoleOutputCP(65001);
    int a, b;
    printf("請輸入兩個整數: ");
    scanf("%d %d", &a, &b);
    printf("加法: %d + %d = %6d\n", a, b, a + b);
    printf("減法: %d - %d = %6d\n", a, b, a - b);
    printf("乘法: %d * %d = %6d\n", a, b, a * b);
    if (b != 0) {
        printf("除法: %d / %d = %6.2f\n", a, b, a / (float)b);
        printf("餘數: %d %% %d = %6d\n", a, b, a % b);
    } else {
        printf("除法和餘數運算無法進行，因為除數為零。\n");
    }
    return 0;
}
