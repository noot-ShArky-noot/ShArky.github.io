#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;

void linknext(Node *newhead, Node *head1, Node *head2);
void display(Node *head);

int main()
{
    Node *head1 = malloc(sizeof(Node));
    head1->data = -1;
    head1->next = NULL;

    Node *head2 = malloc(sizeof(Node));
    head2->data = -1;
    head2->next = NULL;

    Node *newhead = malloc(sizeof(Node));
    newhead->data = -1;
    newhead->next = NULL;

    Node *cur = head1;
    for (int i = 0; i < 5; i++)
    {
        printf("Enter data of the node: ");
        Node *newnode = malloc(sizeof(Node));
        scanf("%d", &newnode->data);

        cur->next = newnode;
        newnode->next = NULL;
        cur = newnode;
    }

    printf("\n");
    cur = head2;
    for (int i = 0; i < 5; i++)
    {
        printf("Enter data of the node: ");
        Node *newnode = malloc(sizeof(Node));
        scanf("%d", &newnode->data);

        cur->next = newnode;
        newnode->next = NULL;
        cur = newnode;
    }

    // head11->head12->head13
    // head21->head22->head23
    // head11->head21->head12->head22->head13->head23

    Node *newwhead=malloc(sizeof(Node));
    newhead->data=-1;
    newhead->next=NULL;
    linknext(newhead, head1, head2);

    display(newhead);
}

void linknext(Node *newhead, Node *head1, Node *head2) { //first connect to second
    Node *cur=newhead;
    Node *p1=head1->next;
    Node *p2=head2->next;

    while(p1!=NULL && p2!=NULL) {
        cur->next=p1;
        cur=p1;
        p1=p1->next;

        cur->next=p2;
        cur=p2;
        p2=p2->next;
    }

    while(p1!=NULL) {
        cur->next=p1;
        cur=p1;
        p1=p1->next;
    }

    while(p2!=NULL) {
        cur->next=p2;
        cur=p2;
        p2=p2->next;
    }
}

void display(Node *head) {
    Node *cur=head;
    printf("head-> ");
    while(cur->next!=NULL){
        cur=cur->next;
        printf("%d-> ", cur->data);
    }
    puts("NULL");
}