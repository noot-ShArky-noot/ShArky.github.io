#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[20];
    int num;
    int score;
    struct node *next;
} Node;

/* ===== 建立新節點 ===== */
Node* createNode(char *name, int num, int score) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->num = num;
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

/* ===== 插入到串列尾巴 ===== */
void insert(Node **head, char *name, int num, int score) {
    Node *newNode = createNode(name, num, score);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *cur = *head;
    while (cur->next != NULL)
        cur = cur->next;

    cur->next = newNode;
}

/* ===== 印出串列 ===== */
void display(Node *head) {
    printf("head->\n");
    while (head != NULL) {
        printf(" name:%-10s num:%d score:%d ->\n",
               head->name, head->num, head->score);
        head = head->next;
    }
    printf("NULL\n");
}

/* ===== 複製串列 ===== */
Node* copyList(Node *head) {
    Node *newHead = NULL;

    while (head != NULL) {
        insert(&newHead, head->name, head->num, head->score);
        head = head->next;
    }

    return newHead;
}

/* ===== swap data ===== */
void swap(Node *a, Node *b) {
    char tempName[20];
    int tempNum, tempScore;

    strcpy(tempName, a->name);
    strcpy(a->name, b->name);
    strcpy(b->name, tempName);

    tempNum = a->num;
    a->num = b->num;
    b->num = tempNum;

    tempScore = a->score;
    a->score = b->score;
    b->score = tempScore;
}

/* ===== 依座號排序（小到大） ===== */
void sortByNum(Node *head) {
    for (Node *i = head; i != NULL; i = i->next) {
        for (Node *j = i->next; j != NULL; j = j->next) {
            if (i->num > j->num)
                swap(i, j);
        }
    }
}

/* ===== 依分數排序（高到低） ===== */
void sortByScore(Node *head) {
    for (Node *i = head; i != NULL; i = i->next) {
        for (Node *j = i->next; j != NULL; j = j->next) {
            if (i->score < j->score)
                swap(i, j);
        }
    }
}

/* ===== 依名字 ASCII 排序（字典序） ===== */
void sortByName(Node *head) {
    for (Node *i = head; i != NULL; i = i->next) {
        for (Node *j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->name, j->name) > 0)
                swap(i, j);
        }
    }
}

/* ===== main ===== */
int main() {
    FILE *fp = fopen("SortVia.txt", "r");
    if (fp == NULL) {
        printf("file open error\n");
        return 1;
    }

    Node *head = NULL;

    char name[20];
    int num, score;

    while (fscanf(fp, "%s %d %d", name, &num, &score) == 3) {
        insert(&head, name, num, score);
    }

    fclose(fp);

    printf("Original list:\n");
    display(head);

    Node *copy = copyList(head);

    printf("\nSorted by num:\n");
    sortByNum(head);
    display(head);

    printf("\nSorted by score:\n");
    sortByScore(copy);
    display(copy);

    printf("\nSorted by name:\n");
    sortByName(head);
    display(head);

    return 0;
}