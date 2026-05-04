#include <stdio.h>
#include <stdlib.h>
void count(int*, int);

int main() {
    int arr[7]={23, 234, 67, 93, 63, 674, 7};
    int n=sizeof(arr)/sizeof(arr[0]);
    count(arr, n);
}

void count(int arr[], int n) {
    int i, odd=0, even=0;
    for (i=0; i<n; i++) {
        arr[i]&1? odd++: even++;
    }
    printf("this array has %d odd numbers\n\t\t\b%d even numbers", odd, even);
}