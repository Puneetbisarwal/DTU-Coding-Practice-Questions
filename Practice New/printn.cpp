#include<bits/stdc++.h>
using namespace std;
class binary
{
	public:
	int data;
	binary *left;
	binary *right;
	binary(int data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
};
/*binary* takeinputofbinarylvlwise()
{
	bool y;
	cin>>y;
	if(!y)
    {
        return NULL;
    }
    int data;
    cin>>data;
    binary *root=new binary(data);
    root->left=takeinputofbinarylvlwise();
    root->right=takeinputofbinarylvlwise();
    return root;
}*/
binary* takeinputofbinarylvlwise()
{
    int data;
    cout<<"enter root data";
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    queue<binary*> pending;
    binary *root=new binary(data);
    pending.push(root);
    while(!pending.empty())
    {
        binary* current=pending.front();
        pending.pop();
        cout<<"enter left child of"<<current->data<<endl;
        int leftchild;
        cin>>leftchild;
        if(leftchild!=-1)
        {
            binary *left=new binary(leftchild);
            current->left=left;
            pending.push(left);
        }
        cout<<"enter right child of"<<current->data<<endl;
        int rightchild;
        cin>>rightchild;
        if(rightchild!=-1)
        {
            binary *right=new binary(rightchild);
            current->right=right;
            pending.push(right);
        }

    }
    return root;
}
void printzigzag(binary *root)
{
    if(root==NULL)
    {
        return;
    }
	stack<binary*> s1,s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty())
	{
		while(!s1.empty())
		{
			binary *curr=s1.top();
			cout<<curr->data<<" ";
			s1.pop();
			if(curr->left!=NULL)
			{
				s2.push(curr->left);
			}
			if(curr->right!=NULL)
			{
				s2.push(curr->right);
			}
		}
		while(!s2.empty())
		{
			binary *curr=s2.top();
			cout<<curr->data<<" ";
			s2.pop();
			if(curr->right!=NULL)
			{
				s1.push(curr->right);
			}
			if(curr->left!=NULL)
			{
				s1.push(curr->left);
			}
		}
	}
}
int main() {
	binary *root=takeinputofbinarylvlwise();
	printzigzag(root);
	return 0;
}
