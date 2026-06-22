#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    char name[20];
    int score1;
    int score2;
    float avg;
    struct node *next;
} Node;

int main() {
    FILE *fp=fopen("inputforfileprac.txt", "r");
}