#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *next;
    node(int data)
    {
        //data=a;
        this->data=data;
        next=NULL;
    }
};
node* input2()
{
    int data;
    cin>>data;
    node *head=NULL,*tail=NULL;
    while(data!=-1)
    {
        node *current=new node(data);
        if(head==NULL)
        {
            head=current;
            tail=current;
        }
        else
        {
            tail->next=current;
            tail=current;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node *t=head;
    while(t!=NULL)
    {
        cout<<t->data<<" -> ";
        t=t->next;
    }
}
node* push(int a,node *head)
{
    node *head1,*tail;
    node *current=new node(a);
    if(head==NULL)
    {
        head1=current;
        tail=current;
    }
    else
    {
        current->next=head1;
        head1=current;
    }
    return head1;
}
int main()
{
    //node *head=input2();
    node *head=NULL;
    cout<< "Enter 1 to push"<<endl;
    cout<<"enter 2 to pop"<<endl;
    cout<<"enter 3 to size"<<endl;
    cout<<"enter 4 to exit"<<endl;
    int a;
    cin>>a;
    switch(a)
    {
    case 1:

    }
    print(head);
    return 0;
}
