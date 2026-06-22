#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//note that the two function below is destructive to the original list so make sure to always copy the list first

typedef struct node {
    char name[20];
    int num;
    int score;
    struct node *next;
}Node;

void display(Node *head);
Node* sortbynum(Node *head);
Node* sortbyscore(Node *head);
Node* copylist(Node *head);

int main() {
    FILE *fp=fopen("SortVia.txt", "r");
    Node *head=malloc(sizeof(Node));
    head->num=-1;
    head->score=-1;
    head->next=NULL;    //LL initialize

    Node *cur=head;
    while (1) {
        char name[20];
        int num, score;

        if (fscanf(fp, "%19s %d %d", name, &num, &score) != 3)
            break;

        Node *newnode = malloc(sizeof(Node));
        strcpy(newnode->name, name);
        newnode->num = num;
        newnode->score = score;

        cur->next = newnode;
        cur = newnode;
        cur->next = NULL;
    }

    //display(sortbynum(copylist(head)));
    printf("\n");
    display(sortbyscore(copylist(head)));

    fclose(fp);
}

void display(Node *head) {
    Node *cur=head;
    printf("Head-> \n");
    while(cur->next!=NULL) {
        cur=cur->next;
        printf("Num:%d Name:%10s Score:%d ->\n", cur->num, cur->name, cur->score);
    }
    puts("NULL");
}

Node* copylist(Node *head) {
    if(head==NULL) return NULL;

    Node *newhead=NULL;
    Node *tail=NULL;
    Node *cur=head;   //skip dummyhead

    while(cur!=NULL) {
        Node *newnode=malloc(sizeof(Node));

        strcpy(newnode->name, cur->name);
        newnode->num=cur->num;
        newnode->score=cur->score;
        newnode->next=NULL;

        if(newhead==NULL) {
            newhead=newnode;
            tail=newnode;
        }
        else {
            tail->next=newnode;
            tail=newnode;
        }
        cur=cur->next;
    }
    return newhead;
}

Node* sortbynum(Node *head) { //from 1 to n...(min to max)
    Node *sorted=NULL;  //create new sorted list (no node yet)

    while(head!=NULL) { //if there is still node in the "unsorted list" then keep doing
        Node *min=head; //current minimal node
        Node *minprev=NULL; //the node before min (this node is used to delete the node we want to delete)
        Node *cur=head; //node for traversal
        Node *prev=NULL;    //the node before current

        //FIND MIN
        while(cur!=NULL) {  //traverse the unsorted list
            if(cur->num < min->num) {   //if there is value smaller than min
                min=cur;    //update min
                minprev=prev;   //update minprev
            }
            prev=cur;   //just path towards the next node normally
            cur=cur->next;  //same for cur
        }

        //remove min from origin
        //situation 1: min is head
        if(minprev==NULL) { //this means min is the first node
            head=head->next;    //move head to next (equals to deleting the first node)
        }
        //situation 2: min is in middle or last
        else {
            minprev->next=min->next;    //skip min and then link previous node to the next node
        }   //minprev -> min -> next        minprev->next

        //link min to sorted
        min->next=NULL; //make min link to null first just in case
        if(sorted==NULL) {  //situation 1: sorted is null
            sorted=min; //
        }
        else {  //situation 2: sorted already has nodes
            Node *t=sorted; //Node t is used to traverse to the end of the list
            while(t->next!=NULL) {
                t=t->next;
            }
            t->next=min;    //link min to the end of the list
        }
    }
    //every round: (1)find min in unsorted (2)remove from unsorted (3)link to sorted
    return sorted;  //return the sorted list
}

Node* sortbyscore(Node *head) {
    Node *sorted = NULL;
    // skip dummy head
    head = head->next;
    while (head != NULL) {

        Node *max = head;
        Node *maxprev = NULL;
        Node *cur = head;
        Node *prev = NULL;

        // find node with highest score
        while (cur != NULL) {
            if (cur->score > max->score) {
                max = cur;
                maxprev = prev;
            }
            prev = cur;
            cur = cur->next;
        }
        // remove max from list
        if (maxprev == NULL) {
            // max is first
            head = head->next;
        }
        else {
            // max in middle or end
            maxprev->next = max->next;
        }
        max->next=NULL;

        //from low to high
        //max->next = sorted;
        //sorted = max;

        //from high to low
        if(sorted==NULL) {
            sorted=max;
            sorted->next=NULL;
        }
        else {
            Node *t=sorted;
            while(t->next!=NULL) {
                t=t->next;
            }
            t->next=max;
            max->next=NULL;
        }
    }
    return sorted;
}
