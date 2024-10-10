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
binary *input()
{
    cout<<"Enter data"<<endl;
    int data;
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    binary *root=new binary(data);
    root->left=input();
    root->right=input();
    return root;
}
void print(binary *root)
{
    if(root==NULL)
    {
        return;

    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
binary *takeinputlvlwise()
{
    cout<<"Root data "<<endl;
    int data;
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    queue<binary*> q;
    binary *root=new binary(data);
    q.push(root);
    while(!q.empty())
    {
        binary *curr=q.front();
        q.pop();
        cout<<"Enter left child of "<<curr->data<<endl;
        int left;
        cin>>left;
        if(left!=-1)
        {
            binary *leftchild=new binary(left);
            curr->left=leftchild;
            q.push(leftchild);
        }
        cout<<"Enter right child of "<<curr->data<<endl;
        int right;
        cin>>right;
        if(right!=-1)
        {
            binary *rightchild=new binary(right);
            curr->right=rightchild;
            q.push(rightchild);
        }
    }
    return root;
}
void printlvlwise(binary *root)
{
    if(root==NULL)
    {
        return;
    }
    queue<binary*> q;
    q.push(root);
    while(!q.empty())
    {
        binary *curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left!=NULL)
        {
            q.push(curr->left);
        }
        if(curr->right!=NULL)
        {
            q.push(curr->right);
        }
    }
}
int main()
{
    //binary *root=input();
    //print(root);
    binary *root=takeinputlvlwise();
    printlvlwise(root);
    return 0;
}
