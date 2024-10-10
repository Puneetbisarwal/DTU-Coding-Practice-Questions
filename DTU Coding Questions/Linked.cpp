#include <stdio.h>
#include <stdlib.h>

struct NodeList {
	int data;
	struct NodeList *next;
};

struct NodeList *head;

void addNode(struct NodeList **node_ref,int x)
{ //struct NodeList* new_node;
    struct NodeList* new_node = (struct NodeList*)malloc(sizeof(struct NodeList));
	new_node->data =x;
	new_node->next=*node_ref;
	*node_ref =  new_node;
}

void printList()
{
    struct NodeList *temp =head;
	printf("List is ");
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main(void) {
	// your code goes here
	head =NULL;

	printf("How many Nodes = \n");
	int n,i,x;
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("Enter the Node = \n");
		scanf("%d",&n);
		addNode(&head,x);
		printList();
	}
	return 0;
}
