#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define size (8)

void display(unsigned int num);

int main() {
    int num=0b10000000;
    /*while(1) {    //10000000 -> 01000000 -> ... -> 00000001
        if(num==0) {
            num=0b10000000;
        }
        display(num);
        //printf("\r");
        num>>=1;
        for(int i=0; i<1e9; i++);
    }*/

    display(num);
    Sleep(100);
    fflush(stdout);
    printf("\r");
    while(1) {
        while(num!=1) {
            num>>=1;
            display(num);
            Sleep(100);
            fflush(stdout);
            printf("\r");
        }
        while(num!=0b10000000) {
            num<<=1;
            display(num);
            Sleep(100);
            fflush(stdout);
            printf("\r");
        }
    }

    /*while(1) {  //chess display
        display(170);
        Sleep(1000);
        fflush(stdout);

        printf("\r");

        display(85);
        Sleep(1000);
        fflush(stdout);

        printf("\r");
    }*/
}
void display(unsigned int num) {
    int i;
    char a[8]={0};
    for(i=size-1; i>=0; i--) { //put from high bit to low bit
        a[i]=num%2+'0';
        num>>=1;
    }
    for(i=0; i<size; i++) {
        printf("%c", a[i]);
    }
    
    //fflush(stdout); //always fflush(stdout) before printf("/r")
    //printf("\r");
    return;
}