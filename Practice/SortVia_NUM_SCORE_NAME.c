#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
    char name[20];
    int num;
    int score;
    struct node *next;
}Node;

void display(Node *head);
Node* sortbynum(Node *head);
Node* sortbyscore(Node *head);

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

    display(sortbynum(head));
    printf("\n");
    display(sortbyscore(head));

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

Node* sortbyscore(Node *head) { //from 1 to n...(min to max)
    Node *sorted=NULL;  //create new sorted list (no node yet)

    while(head!=NULL) { //if there is still node in the "unsorted list" then keep doing
        Node *max=head; //current minimal node
        Node *maxprev=NULL; //the node before min (this node is used to delete the node we want to delete)
        Node *cur=head; //node for traversal
        Node *prev=NULL;    //the node before current

        //FIND MAX
        while(cur!=NULL) {  //traverse the unsorted list
            if(cur->score > max->score) {   //if there is value larger than max
                max=cur;    //update max
                maxprev=prev;   //update maxprev
            }
            prev=cur;   //just path towards the next node normally
            cur=cur->next;  //same for cur
        }

        //remove min from origin
        //situation 1: min is head
        if(maxprev==NULL) { //this means min is the first node
            head=head->next;    //move head to next (equals to deleting the first node)
        }
        //situation 2: min is in middle or last
        else {
            maxprev->next=max->next;    //skip min and then link previous node to the next node
        }   //minprev -> min -> next        minprev->next

        //link min to sorted
        max->next=NULL; //make min link to null first just in case
        if(sorted==NULL) {  //situation 1: sorted is null
            sorted=max; //
        }
        else {  //situation 2: sorted already has nodes
            Node *t=sorted; //Node t is used to traverse to the end of the list
            while(t->next!=NULL) {
                t=t->next;
            }
            t->next=max;    //link min to the end of the list
        }
    }
    //every round: (1)find min in unsorted (2)remove from unsorted (3)link to sorted
    return sorted;  //return the sorted list
}
