// 5-0 B11400002 余承翰
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// #include <windows.h>

int main(){
    // SetConsoleOutputCP(65001);
    int i, decimalsum= 0;
    char ch[i];
    char choutput[5];

    for (i=0; i<4; i++){
        ch[i]= getche();
        choutput[i]= ch[i];
        if (ch[i]>='A' && ch[i]<='F'){
            ch[i]=ch[i]-'A'+10;
        }
        else if (ch[i]>='a' && ch[i]<='f'){
            ch[i]=ch[i]-'a'+10;
        }
        else if (ch[i]>='0' && ch[i]<='9'){
            ch[i]=ch[i]-'0';
        }
        else{
            ch[i]=0;
        }
        decimalsum= decimalsum*16+ch[i];
    }
    printf("\n%s %d", choutput, decimalsum);
    return 0;
}