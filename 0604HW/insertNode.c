#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void insert(Node **head, int pos, int value)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = value;

    if (pos == 0) {
        newnode->next = *head;
        *head = newnode;
        return;
    }
    Node *p = *head;

    for(int i = 0; i < pos - 1; i++) {
        if(p == NULL) {
            printf("位置不存在\n");
            free(newnode);
            return;
        }
        p = p->next;
    }
    if (p == NULL) {
        printf("位置不存在\n");
        free(newnode);
        return;
    }

    newnode->next = p->next;
    p->next = newnode;
}

void printList(Node *head)
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void freeList(Node *head)
{
    Node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node *head = NULL;

    insert(&head, 0, 10);
    insert(&head, 1, 20);
    insert(&head, 2, 30);
    insert(&head, 3, 40);

    printList(head);
    insert(&head, 2, 99);
    printList(head);
    freeList(head);

    return 0;
}