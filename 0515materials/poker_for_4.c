#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int deck[52];

    // 初始化牌組
    for(int i = 0; i < 52; i++) {
        deck[i] = i;
    }

    // 隨機種子
    srand(time(NULL));

    // 洗牌
    for(int i = 0; i < 52; i++) {

        int j = rand() % 52;

        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // 花色與數字
    char *suit[] = {"♠", "♥", "♦", "♣"};
    char *rank[] = {
        "A", "2", "3", "4", "5", "6", "7",
        "8", "9", "10", "J", "Q", "K"
    };

    // 發牌
    for(int player = 0; player < 4; player++) {

        printf("玩家 %d 的牌：\n", player + 1);

        for(int card = 0; card < 13; card++) {

            int value = deck[player * 13 + card];

            int s = value / 13;
            int r = value % 13;

            printf("%s%s ", suit[s], rank[r]);
        }

        printf("\n\n");
    }

    return 0;
}