#include <stdio.h>
#include <stdlib.h>
#define row (3)
#define col (2)
void add(int (*A)[col], int (*B)[col], int (*C)[col]);

int main() {
    int i, j;
    int a[row][col]={{17, 29}, {38, 6}, {12, 4}};
    int b[row][col]={{17, 29}, {38, 6}, {12, 4}};
    int c[row][col]={0};
    add(a, b, c);
    for (i=0; i<row; i++) {
        for (j=0; j<col; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}
void add(int A[row][col], int B[row][col], int C[row][col]) {
    int i, j;
    for (i=0; i<row; i++) {
        for (j=0; j<col; j++) {
            C[i][j]=A[i][j]+B[i][j];
        }
    }
}