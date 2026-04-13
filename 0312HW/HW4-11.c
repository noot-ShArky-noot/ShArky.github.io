// 4-11 B11400002 余承翰

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    int student_id;
    int student_age;
    printf("請輸入學號：");
    scanf("%d", &student_id);
    printf("請輸入年齡：");
    scanf("%d", &student_age);
    printf("學生的學號是：%d\n", student_id);
    printf("學生的年齡是：%d\n", student_age);
    return 0;       
}