#include <stdio.h>
#include <stdlib.h>

int main() {
    int w;

    scanf("%d", &w);
    if(w> 90){
        printf("體重過重");
    }
    else {
        printf("不會過重");
    }

    return 0;
}