#include <stdio.h>

char map(int n)
{
    if (n >= 0 && n <= 9)
        return n + '0';
    else if (n >= 10 && n <= 35)
        return (n - 10) + 'A';
    else
        return (n - 36) + 'a';   // 36~61
}

void convert(int num, int base)
{
    char result[200];
    int i = 0;

    if (base < 2 || base > 62) {
        printf("Invalid base (2~62 only)\n");
        return;
    }

    if (num == 0) {
        printf("0\n");
        return;
    }

    int neg = 0;
    if (num < 0) {
        neg = 1;
        num = -num;
    }

    while (num > 0) {
        int r = num % base;
        result[i++] = map(r);
        num /= base;
    }

    if (neg) printf("-");

    printf("Result: ");

    for (int j = i - 1; j >= 0; j--) {
        printf("%c", result[j]);
    }

    printf("\n");
}

int main()
{
    int num, base;

    printf("Enter decimal number: ");
    scanf("%d", &num);

    printf("Enter base (2~62): ");
    scanf("%d", &base);

    convert(num, base);

    return 0;
}