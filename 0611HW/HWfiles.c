#include <stdio.h>
#include <stdlib.h>
#define max 10
typedef struct node {
    int c;
    int math;
    float avg;
    char name[10];
    struct node *next;
}Node;

void display(Node *p);

int main() {
    FILE *fp=fopen("input.txt", "r");
    int C, Math, i;
    char *Name;
    Node *head=malloc(sizeof(Node));
    head->c=-1;
    head->math=-1;
    head->next=NULL;
    Node *newnode;
    Node *cur;

    cur=head;
    while(1) {
        newnode=malloc(sizeof(Node));
        if (fscanf(fp, "%s %d %d", newnode->name, &newnode->c, &newnode->math) != 3) {
            free(newnode);
            break;
        }
        newnode->avg=((float)(newnode->c+newnode->math))/2;
        cur->next=newnode;
        newnode->next=NULL;
        cur=newnode; 
    }

    display(head);
}

void display(Node *p) {
    Node *cur=p;
    printf("Head->\n");
    while(cur->next!=NULL) {
        cur=cur->next;
        printf("name: %-6s avg: %.1f->\n", cur->name, cur->avg);
    }
    puts("->NULL");
}