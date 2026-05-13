#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    char *suit[] = {"♠", "♥", "♦", "♣"};
    char *rank[] = {
        "A","2","3","4","5","6",
        "7","8","9","10","J","Q","K"
    };

    srand(time(NULL));

    for(int i=0;i<5;i++) {

        int s = rand() % 4;
        int r = rand() % 13;

        printf("%s%s\n", suit[s], rank[r]);
    }

    return 0;
}