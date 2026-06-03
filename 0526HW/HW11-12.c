#include <stdio.h>
#include <stdlib.h>
#define Max (2)

struct data {
    char name[10];
    int math;
}student[Max];

int main() {
    int i;
    struct data *p=student;
    for(i=0; i<Max; i++) {
        printf("Student name: ");
        scanf("%s", (p+i)->name);
        printf("Math score: ");
        scanf("%d",&(p+i)->math);
        while(getchar() != '\n');
    }
    for(i=0; i<Max; i++)
        printf("%s's math score is %d\n",(p+i)->name, (p+i)->math);
}