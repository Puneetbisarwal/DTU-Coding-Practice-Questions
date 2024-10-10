#include <stdio.h>
#include <stdlib.h>

struct NodeList {
	int data;
	struct NodeList *next;
};



 void addNode( struct NodeList** node_ref ,int x)
{

    struct NodeList* new_node = (struct NodeList*)malloc(sizeof(struct NodeList));
	new_node->data =x;
	new_node->next=*node_ref;
	*node_ref =  new_node;


}


void append( struct NodeList** node_ref ,int x)
{
    struct NodeList *lastnode = *node_ref;

    struct NodeList* new_node = (struct NodeList*)malloc(sizeof(struct NodeList));
	new_node->data =x;
	new_node->next=NULL;

	if(*node_ref == NULL)
    {
	*node_ref =  new_node;
	return;
    }

    while(lastnode->next!=NULL)
    {
        lastnode=lastnode->next;
    }

    lastnode->next=new_node;
    return;
}



 void InsertNodeAfter( struct NodeList** node_pre ,int x)
{
    if(*node_pre == NULL)
    {
       printf("Previous node is null");
      return;
    }
    struct NodeList* new_node = (struct NodeList*)malloc(sizeof(struct NodeList));
	new_node->data =x;
	new_node->next=(*node_pre)->next;
	(*node_pre)->next =  new_node;


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


        addNode(&head,8);
        printList(head);
		addNode(&head,6);
		printList(head);
		append(&head,9);
		printList(head);
		InsertNodeAfter(&head,7);
		printf("Created Linked list is: ");
        printList(head);

	return 0;
}
