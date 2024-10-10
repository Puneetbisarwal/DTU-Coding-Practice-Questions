#include <iostream>

using namespace std;
class Node{

public:
    int data;
    Node *next;


};

 void push(Node **head, int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        Node *temp = head;

        if(temp == NULL)
        {
            temp = newNode;
            //return temp;
        }

        while(temp != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        //return head;
    }

    void print(Node *head)
    {
        if(head == NULL)
           {

            cout<<"LL empty";
            return;
           }
           while(head != NULL)
           {

               cout<<head->data<<" ";
               head = head->next;
           }
    }


int main()
{
    Node *head = NULL;

    push(head,1);
    push(head,2);
    print(head);
    return 0;
}
