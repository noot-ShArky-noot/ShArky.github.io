#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;
void displayHeadNull(Node* p);
void display(Node* p);

int main() {
    //one thing super important is that you should never lose track of head
    Node *head;
    head= (Node*)malloc(sizeof(Node)); //upon making a new node you have to malloc agian for the new node
    head->data=-1; //usually we want head to be just a leading character, so it can store nothing.
    head->next=NULL;

    Node *newnode; //note that newnode is just a pointer, it has no memory allocated to it yet
    newnode= (Node*)malloc(sizeof(Node));
    newnode->data=10;
    newnode->next=NULL;

    head->next=newnode;

    newnode= (Node*)malloc(sizeof(Node)); //every time we do malloc, we are allocating a new memory and makes newnode point to it
    newnode->data=20;
    newnode->next=NULL;

    head->next->next=newnode;

    newnode= (Node*)malloc(sizeof(Node));
    newnode->data=30;
    newnode->next=NULL;
    
    head->next->next->next=newnode; //we've created 1+3 nodes and linked them together so far

    printf("this is the linked list containing head and 3 nodes\n");
    displayHeadNull(head);

    //traversing the linked list
    //this method is for the times you don't set head to store nothing
    //if head stores nothing then see the display() function
    //you have to move to pointer first if head stores nothing
    Node* current;
    current=head;
    while(current!=NULL) {
        printf("%d->", current->data);
        current=current->next;
    }
    printf("\n");

    //inserting a node
    newnode=(Node*)malloc(sizeof(Node));
    newnode->data=25;
    newnode->next=head->next; //newnode now points to the second node
    head->next=newnode; //making head points to newnode, so (head)->(newnode)->(second node)
    display(head);

    //deleting a node
    printf("\nthis is the list before deleting the node after head:");
    display(head);
    Node* temp;
    temp=head->next;
    head->next=temp->next;
    free(temp);
    printf("this is the list after deleting the node after head:");
    display(head);
}

void displayHeadNull(Node* p) {
    printf("Head->"); //head stores nothing so we print out head just so we know the list has started
    while(p->next!=NULL) { //if there is still another node after this node, then
        p=p->next; //moves pointer to the next node, so Node1[Current]->Node2[Next] becomes Node1[Previous]->Node2[Current]
        printf("%d->", p->data); //print out the data of this current node
    }   //so we are moving the pointer first then we print out the data
    puts("NULL");
}

void display(Node *p) { //starts printing the list frome pointer p
    Node* current;
    current=p;
    while(current!=NULL) {
        printf("%d->", current->data);
        current=current->next;
    }
    printf("\n");
}