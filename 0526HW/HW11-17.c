#include <stdio.h>
#include <stdlib.h>
#define Max 5

struct data {
    char name[10];
    int math;
}student[Max];

struct data best(struct data student[]) {
    struct data max = student[0];

    for(int i = 1; i < Max; i++) {
        if(student[i].math > max.math)
            max = student[i];
    }
    return max;
}

void failed(struct data student[]) {
    for(int i = 0; i < Max; i++) {
        if(student[i].math < 60) {
            printf("%s failed with %d\n",
                   student[i].name,
                   student[i].math);
        }
    }
}

double average(struct data student[]) {
    int sum = 0;

    for(int i = 0; i < Max; i++) {
        sum += student[i].math;
    }

    return (double)sum / Max;
}

void sort(struct data student[]) {
    struct data temp;

    for(int i = 0; i < Max - 1; i++) {
        for(int j = i + 1; j < Max; j++) {
            if(student[i].math < student[j].math) {
                temp = student[i];
                student[i] = student[j];
                student[j] = temp;
            }
        }
    }
}

int main() {
    for(int i = 0; i < Max; i++) {
        printf("Name: ");
        scanf("%9s", student[i].name);

        printf("Math: ");
        scanf("%d", &student[i].math);
    }

    struct data top = best(student);
    printf("\nBest student: %s %d\n", top.name, top.math);

    printf("\nFailed students:\n");
    failed(student);

    printf("\nAverage = %.2f\n", average(student));

    sort(student);

    printf("\nAfter sorting (high → low):\n");
    for(int i = 0; i < Max; i++) {
        printf("%s %d\n", student[i].name, student[i].math);
    }

    return 0;
}