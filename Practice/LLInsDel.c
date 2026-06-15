#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
}Node;
//whenever we see "a->next=b", translate it to "node a now points to node b"
//if we see "a=b->next(or data)" instead, then translate it to "node a is now node b->next(or data)"

void display(Node *p);
void insert(Node *head, int target, int newvalue);
void insertFront(Node *head, int newvalue);
void delete(Node *head, int target);
void build(Node *head, int arr[], int n);

int main() {
    Node *head;
    head=(Node*)malloc(sizeof(Node));
    head->data=-1;
    head->next=NULL;    //we don't have another node just yet, so NULL is just fine
    int arr[5]={10,20,30,40,50};

    build(head, arr, sizeof(arr)/sizeof(arr[0]));
    display(head);
    insert(head, 30, 35);
    display(head);
    insertFront(head, 5);
    display(head);
    delete(head, 40);
    display(head);

    return 0;
}

void display(Node *p) {
    printf("Head->");
    while(p->next!=NULL) {
        p=p->next;
        printf("%d->", p->data);
    }
    puts("NULL");
}

void build(Node *head, int arr[], int n) {
    Node *tail=head;
    int i;
    for(i=0; i<n; i++) {
        Node *newnode=(Node*)malloc(sizeof(Node));
        newnode->data=arr[i];
        newnode->next=NULL;

        tail->next=newnode; //connecting with the node before
        tail=newnode; //moving pointer tail to the tail of the linked list
        //pointing tail to newnode->next: since newnode originally points to nothing(it's at the end of the list)
        //so by doing so we can move tail to the end of the list
    }
}

//making insert is just finding the target, connect current and the node after, then connect with the node before
//note that the target here is the data stored in the node: int data
void insert(Node *head, int target, int newvalue) {
    Node *current=head->next;   //start searching from the second node, skipping the virtual head
    while(current!=NULL) {
        if (current->data==target) {    //if we found the data(target) we want, 
            Node *newnode=(Node*)malloc(sizeof(Node));  //create a newnode and allocate a slice of memry to it
            newnode->data=newvalue;     //set to data
            newnode->next=current->next;    //connect with the node after
            current->next=newnode;  //connect with the node before
            /*
            the process look like this:
            step 1(neutral state): head->node1->target->node3->NULL
            step 2(finding the target): head->node1->target->node2->NULL
                                                    [found!]: current->target
            step 3(creating newnode):               NULL->newnode->NULL 
            step 4(connecting with the node after): head->node1->target->node3->NULL
                                                    current->target    NULL->newnode->node3
            step 5(connecting with the node before): head->node1->target->node3->NULL
                                                    current->target    current(target)->newnode->node3
            Now the full Linked list looked like this:
            head->node1->target->newnode->node3->null
            */
           return;
        }
        current=current->next;  //moving on to the next node
    }
}

void insertFront(Node *head, int newvalue) {
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=newvalue;     //assign newvalue to the data attribute of the node
    newnode->next=head->next;   //connect to the node after
    head->next=newnode;    //connect to the node before
}

void delete(Node *head, int target) {   //deletes node that fits the target requirement(delete by value)
    Node *current=head;
    while(current->next!=NULL) {    //we are not at the end of the linked list, look at line
        if (current->next->data==target) {  //target found!(current->next is the target)
            Node *temp=current->next;   //line 72 to 75 is a classic way to delete a node, by pointing the node before the target to the node after the target and free-ing the target node
            current->next=temp->next;
            free(temp);
            return;
        }
        current=current->next;  //so we keep going...
    }
}