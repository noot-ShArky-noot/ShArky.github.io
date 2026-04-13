#include <stdio.h>
#include <stdlib.h>

int main() {
    int total, change, money, money1;
    int n1000, n500, n100, n50, n10, n5, n1;

    printf("enter total and your money: ");
    scanf("%d %d", &total ,&money);

    if (money < total) {
        printf("金額不足");
    }
    else if (money == total) {
        printf("找回0元");
    }
    else {
        money = money - total;
        money1 = money;
        n1000 = money/1000;
        money = money%1000;

        n500 = money/500;
        money = money%500;

        n100 = money/100;
        money = money%100;

        n50 = money/50;
        money = money%50;
        
        n10 = money/10;
        money = money%10;

        n5 = money/5;
        
        n1 = money%5;

        printf("找回%d張1000元, 找回%d張500元, 找回%d張100元, 找回%d個50元, 找回%d個10元, 找回%d個5元, 找回%d個1元, 總共%d元", n1000, n500, n100, n50, n10, n5, n1, money1);
    }
}