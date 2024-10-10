#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
	int data;
	node *next;
	node(int data)
	{
		this->data=data;
		next=NULL;
	}
};
node* input()
{
    int data;
    cin>>data;
    node *head=NULL,*tail=NULL;
    while(data!=-1)
    {
        node *currentnode=new node(data);
        if(head==NULL)
        {
            head=currentnode;
            tail=currentnode;
        }
        else
        {
            tail->next=currentnode;
            tail=currentnode;
        }

        cin>>data;
    }
    return head;
}
void print(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
node *revll(node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node *ans=revll(head->next);
    head->next->next=head;
    head->next=NULL;
    return ans;
}
bool palindrome(node *head)
{
    node *temp=head;
    node *slow=head,*fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    node *temp2=slow->next;
    node *ans=revll(slow->next);
    slow->next=ans;
    while(ans!=NULL)
    {
        if(temp->data!=ans->data)
        {
            return false;
        }
        temp=temp->next;
        ans=ans->next;
    }
    return true;
}
istream& operator>>(istream & is , node *&head)
{
    head=input();
    return is;
}
ostream& operator<<(ostream &os , node *head)
{
    print(head);
    return os;
}
int main() {
    node *head;
	cin>>head;
	cout<<head;
	//cout<<palindrome(head);
	return 0;
}
