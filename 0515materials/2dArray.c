#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[][3], int row) {
    for(int i=0;i<row;i++) {
        for(int j=0;j<3;j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[2][3] = {
        {1,2,3},
        {4,5,6}
    };

    printArray(a, 2);

    return 0;
}