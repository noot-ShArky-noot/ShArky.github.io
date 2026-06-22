#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int class;
    char name[20];
    int num;
    int score;
    struct node *next;
} Node;

/* ================== create node ================== */
Node* createNode(int class, char *name, int num, int score) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->class = class;
    strcpy(newNode->name, name);
    newNode->num = num;
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

/* ================== insert to end ================== */
void insert(Node **head, int class, char *name, int num, int score) {
    Node *newNode = createNode(class, name, num, score);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *cur = *head;
    while (cur->next != NULL)
        cur = cur->next;

    cur->next = newNode;
}

/* ================== display ================== */
void display(Node *head) {
    printf("head->\n");

    while (head != NULL) {
        printf(" class:%d name:%-8s num:%d score:%d ->\n",
               head->class, head->name, head->num, head->score);
        head = head->next;
    }

    printf("NULL\n");
}

/* ================== swap data ================== */
void swap(Node *a, Node *b) {
    int tclass = a->class;
    char tname[20];
    int tnum = a->num;
    int tscore = a->score;

    strcpy(tname, a->name);

    a->class = b->class;
    strcpy(a->name, b->name);
    a->num = b->num;
    a->score = b->score;

    b->class = tclass;
    strcpy(b->name, tname);
    b->num = tnum;
    b->score = tscore;
}

/* ================== sort by class ================== */
void sortByClass(Node *head) {
    for (Node *i = head; i != NULL; i = i->next)
        for (Node *j = i->next; j != NULL; j = j->next)
            if (i->class > j->class)
                swap(i, j);
}

/* ================== merge ================== */
Node* merge(Node *a, Node *b) {
    Node *res = NULL;

    while (a) {
        insert(&res, a->class, a->name, a->num, a->score);
        a = a->next;
    }

    while (b) {
        insert(&res, b->class, b->name, b->num, b->score);
        b = b->next;
    }

    sortByClass(res);
    return res;
}

/* ================== split helper ================== */
Node* filter(Node *head, int (*cond)(Node*)) { //traverse + new list
    Node *res = NULL;

    while (head) {
        if (cond(head))
            insert(&res, head->class, head->name, head->num, head->score);
        head = head->next;
    }

    return res;
}

/* ===== conditional function（class / name / num / score） ===== */
int cond_class(Node *n) { return n->class >= 0; } // 全部
int cond_name(Node *n)  { return n->name[0] >= 0; }
int cond_num(Node *n)   { return n->num >= 0; }
int cond_score(Node *n) { return n->score >= 0; }

/* ================== main ================== */
int main() {
    FILE *fp1 = fopen("MergeSplitA.txt", "r");
    FILE *fp2 = fopen("MergeSplitB.txt", "r");

    if (!fp1 || !fp2) {
        printf("file open error\n");
        return 1;
    }

    Node *h1 = NULL;
    Node *h2 = NULL;

    int c, n, num, score;
    char name[20];

    while (fscanf(fp1, "%d %s %d %d", &c, name, &num, &score) == 4)
        insert(&h1, c, name, num, score);

    while (fscanf(fp2, "%d %s %d %d", &c, name, &num, &score) == 4)
        insert(&h2, c, name, num, score);

    fclose(fp1);
    fclose(fp2);

    printf("List 1:\n");
    display(h1);

    printf("\nList 2:\n");
    display(h2);

    Node *merged = merge(h1, h2);

    printf("\nMerged & sorted by class:\n");
    display(merged);

    /* ===== split 4type ===== */
    Node *byClass = filter(merged, cond_class);
    Node *byName  = filter(merged, cond_name);
    Node *byNum   = filter(merged, cond_num);
    Node *byScore = filter(merged, cond_score);

    printf("\nSplit by class:\n");
    display(byClass);

    printf("\nSplit by name:\n");
    display(byName);

    printf("\nSplit by num:\n");
    display(byNum);

    printf("\nSplit by score:\n");
    display(byScore);

    return 0;
}