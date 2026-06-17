#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
    int id;
    char name [20];
    float score;
    struct node *next;
} Node;
void display(Node *p);
void insert(Node*p, int pos, Node *data);
void delete(Node *p, int id);
Node* findmax(Node* p);

int main () {
    Node *head=malloc(sizeof(Node));    //initailize linked list
    head->id=-2;
    head->score=-1;
    head->next=NULL;
    Node *cur=malloc(sizeof(Node));
    
    cur=head;
    int tempID=0, listcount=0;
    while(1) {
        tempID=0;
        printf("please enter student id (enter -1 to leave): ");
        scanf("%d", &tempID);
        
        if (tempID==-1) {
            break;
        }
        else {
            Node *newnode=malloc(sizeof(Node));
            newnode->id=tempID;
            printf("enter student name: ");
            scanf("%s", newnode->name);
            printf("enter student score: ");
            scanf("%f", &newnode->score);
            cur->next=newnode;
            cur=newnode;
            newnode->next=NULL;
            listcount++;
        }
    }
    if(listcount!=0){
        display(head);
        printf("\n");
    }

    Node *newStudentData=malloc(sizeof(Node));
    newStudentData->id=1010;
    strcpy(newStudentData->name, "oof");
    newStudentData->score=97;
    insert(head, 2, newStudentData);
    display(head);

    delete(head, 1000);
    display(head);

    printf("\nMax score is %f, from %s\n", findmax(head)->score, findmax(head)->name);
}

void display(Node *p) { //completed
    Node *cur=malloc(sizeof(Node));
    cur=p;
    puts("head->");
    while (cur->next!=NULL) {
        cur=cur->next;
        printf("student id=%d, name=%s, score=%f ->\n", cur->id, cur->name, cur->score);
    }
    puts("NULL");
}

void insert(Node*p, int pos, Node *data) { //completed
    Node *cur=malloc(sizeof(Node));
    cur=p;
    int count=0;
    for(; count<pos && cur!=NULL; count++) {
        cur=cur->next;
    }
    if(cur==NULL) return;
    Node *newnode=data;
    newnode->next=cur->next;
    cur->next=newnode;
}

//never malloc when deleting nodes, malloc is for CREATING nodes, not deleting.
void delete(Node *p, int id) {
    Node *cur=p;
    while(cur->next!=NULL) {
        if ((cur->next->id)==id) {
            Node *temp=cur->next;
            cur->next=temp->next;
            free(temp);
            return;
        }
        cur=cur->next;
    }
}

Node* findmax(Node* p) {
    if(p==NULL || p->next==NULL)
        return NULL;

    Node* cur=p->next;
    Node* max=p->next;

    while(cur!=NULL) {
        if(cur->score > max->score) {
            max=cur;
        }
        cur=cur->next;
    }
    return max;
}