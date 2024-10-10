#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
	struct Node *prev;

};

struct Node* GetNode(int x)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node*));
    new_node->data=x;
    new_node->next=NULL;
    new_node->prev=NULL;
    return new_node;
}

void Insert(struct Node **new_ref,int x)
{

    struct Node* new_node =  GetNode(x);

    if(*new_ref == NULL)
    {
        *new_ref = new_node;
        return;
    }

    (*new_ref)->prev = new_node;
    new_node->next= *new_ref;
    *new_ref = new_node;

    //struct Node* new_node = (struct Node*) malloc(sizeof(struct Node*));
//    new_node->data=x;
//    new_node->next=*new_ref;
//    new_node->prev =NULL;

//    if ((*new_ref) != NULL)
//        (*new_ref)->prev = new_node;
//    *new_ref=new_node;

}


void printForward(struct Node *node)
{

    printf("\n Forward Direction \n");
    while (node != NULL)
        {
        printf(" %d ", node->data);
        node = node->next;
        }
        printf("\n");
}


void printReverse(struct Node *node)
{
    if(node==NULL)
        return;

    printf("\n Reverse Direction \n");
    while (node->next != NULL)
        {
        node = node->next;
        }

        while(node!=NULL)
        {
          printf(" %d ",node->data);
          node=node->prev;
        }
        printf("\n");

}

void printNode(struct Node* node)
{
    struct Node* last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL) {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf(" %d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

int main(void) {
	// your code goes here
       struct Node* head =NULL;

        Insert(&head,50);
        //printNode(head);
        Insert(&head,60);
        printNode(head);
        Insert(&head,70);
        printNode(head);
        printForward(head);
        printReverse(head);

	return 0;
}
