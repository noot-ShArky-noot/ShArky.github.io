#include <stdio.h>
#include <stdlib.h>

int main() {

    int h = 5;

    int width = 2*h - 1;

    int mid = width / 2;

    for(int y=0; y<h; y++) {

        for(int x=0; x<width; x++) {

            if(x >= mid-y &&
               x <= mid+y)

                printf("*");

            else
                printf(" ");
        }

        printf("\n");
    }

    return 0;
}

/*int main() {
    int x, y, n;
    scanf("%d", &n);

    for(y=n; y>=-n; y--) {
        for(x=-n; x<=n; x++) {
            **********
            this is framework
            **********
        }
    }
}*/