#include <stdio.h>
#include <stdlib.h>

struct NodeList {
	int data;
	struct NodeList *next;
};



 void Insert( struct NodeList** node_ref ,int x)
{

    struct NodeList* new_node = (struct NodeList*)malloc(sizeof(struct NodeList));
	new_node->data =x;
	new_node->next=*node_ref;
	*node_ref =  new_node;


}


void deleteNode(struct NodeList **node_ref,int x)
{

    struct NodeList* temp =*node_ref;
    struct NodeList* prev;

    if(temp !=NULL && temp->data == x)
    {
        *node_ref= (*node_ref)->next;
        free(temp);
        return;
    }

    while(temp!=NULL && temp->data!=x)
    {
        prev=temp;
        temp=temp->next;
    }

     if(temp==NULL)
     {
         printf("Node does not present");
         return;
     }

     prev->next=temp->next;

     free(temp);

}

void printList(struct NodeList *temp)
{
	printf("List is ");
	while(temp!=NULL)
	{
		printf(" %d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main(void) {
	// your code goes here
       struct NodeList* head =NULL;

        Insert(&head,6);
        Insert(&head,7);
        Insert(&head,8);
		Insert(&head,9);
		printf("Created Linked list is: ");
        printList(head);
        deleteNode(&head,8);
        printList(head);

	return 0;
}
