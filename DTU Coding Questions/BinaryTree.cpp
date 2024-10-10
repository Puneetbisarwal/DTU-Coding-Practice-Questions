#include<iostream>
#include<queue>
#include<bits/stdc++.h>
#include"binary.h"
#include<vector>

using namespace std;

template<typename T>

class node
{
    public:
    T data;
    node *next;
    node(T data)
    {
        this->data=data;
        next=NULL;
    }
};

binary <int>* takeinputofbinarylvlwise()
{
    int data;
    cout<<"enter root data";
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    queue<binary<int>*> pending;
    binary<int> *root=new binary<int>(data);
    pending.push(root);
    while(!pending.empty())
    {
        binary<int>* current=pending.front();
        pending.pop();
        cout<<"enter left child of"<<current->data<<endl;
        int leftchild;
        cin>>leftchild;
        if(leftchild!=-1)
        {
            binary<int> *left=new binary<int>(leftchild);
            current->left=left;
            pending.push(left);
        }
        cout<<"enter right child of"<<current->data<<endl;
        int rightchild;
        cin>>rightchild;
        if(rightchild!=-1)
        {
            binary<int> *right=new binary<int>(rightchild);
            current->right=right;
            pending.push(right);
        }

    }
    return root;
}
void printbinary(binary<int> *root)
{

    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    printbinary(root->left);
    printbinary(root->right);
}
void printvertical(binary<int> *root,int hd ,map<int,vector<int>> &m)
{
    if(root==NULL)
    {
        return;
    }
    m[hd].push_back(root->data);
    printvertical(root->left,hd-1,m);
    printvertical(root->right,hd+1,m);
}
void callprintvertical(binary<int> *root)
{
    map<int,vector<int>> m;
    printvertical(root,0,m);
    for(auto i=m.begin();i!=m.end();i++)
    {
        for(int it=0;it<i->second.size();it++)
        {
            cout<<i->second[it]<<" ";
        }
        cout<<endl;
    }
}
void printlevel(binary<int> *root)
{
    queue<binary<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        binary<int> *current=q.front();
        if(current==NULL)
        {
            if(q.size()>1)
            {
            q.pop();
            cout<<endl;
            q.push(NULL);
            continue;
            }
            else
            {
                return;
            }
        }
        q.pop();
        cout<<current->data<<" ";
        if(current->left!=NULL)
        q.push(current->left);
        if(current->right!=NULL)
        q.push(current->right);

    }
}
void leftview(binary<int> *root,int level,int &max_level)
{
    if(root==NULL)
    {
        return;
    }
    if(max_level<level)
    {
        cout<<root->data<<endl;
        max_level=level;
    }
    leftview(root->left,level+1,max_level);
    leftview(root->right,level+1,max_level);
}
void rightview(binary<int> *root,int level,int &max_level)
{
    if(root==NULL)
    {
        return;
    }
    if(max_level<level)
    {
        cout<<root->data<<endl;
        max_level=level;
    }
    rightview(root->right,level+1,max_level);
    rightview(root->left,level+1,max_level);
}
void printtopview(binary<int> *root,int hd,map<int,vector<int>> &m)
{
    if(root==NULL)
    {
        return;
    }
    m[hd].push_back(root->data);
    printtopview(root->left,hd-1,m);
    printtopview(root->right,hd+1,m);
}
void topviewprint(binary<int> *root)
{
    map<int,vector<int>> m;
    printtopview(root,0,m);
    int s=m.size();
    for(auto i=m.begin();i!=m.end();i++)
    {
        cout<<i->second[0];
        cout<<endl;
    }
}
void bottomview(binary<int> *root,int hd,map<int,vector<int>> &m)
{
    if(root==NULL)
    {
        return;
    }
    m[hd].push_back(root->data);
    bottomview(root->left,hd-1,m);
    bottomview(root->right,hd+1,m);
}
void bottomviewprint(binary<int> *root)
{
    map<int,vector<int>> m;
    bottomview(root,0,m);
    for(auto i=m.begin();i!=m.end();i++)
    {
        int s=i->second.size();
        cout<<i->second[s-1];
        cout<<endl;
    }
}
bool isbst(binary<int>* root,int a,int b)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data < b || root->data >a)
    {
        return false;
    }
    return isbst(root->left,root->data-1,b)&&
    isbst(root->right,a,root->data+1);
}
bool isleaf(binary<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return true;
    }
    return false;
}
int sumleftleaf(binary<int> *root)
{
    int res=0;
    if(root!=NULL)
    {
        if(isleaf(root->left))
        {
            res=res+root->left->data;
        }
        else
        {
            res=res+sumleftleaf(root->left);
        }
        res=res+sumleftleaf(root->right);
    }
    return res;
}
void printnodeatkdistance(binary<int> *root ,int k)
{
    if(root==NULL || k<0)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<", ";
    }
    printnodeatkdistance(root->left,k-1);
    printnodeatkdistance(root->right,k-1);
}
int printnodeatkdistancefromgivennode(binary<int> *root,binary<int> *target,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root==target)
    {
        printnodeatkdistance(root,k);
        return 0;
    }
    int ld=printnodeatkdistancefromgivennode(root->left,target,k);
    if(ld!=-1)
    {
        if(ld+1==k)
        {
            cout<<root->data<<", ";
        }
        else
        {
            printnodeatkdistance(root->right,k-ld-2);
        }
        return ld+1;
    }
    int rd=printnodeatkdistancefromgivennode(root->right,target,k);
    if(rd!=-1)
    {
        if(rd+1==k)
        {
            cout<<root->data<<", ";
        }
        else
        {
            printnodeatkdistance(root->left,k-rd-2);
        }
        return rd+1;
    }
    return -1;
}
void printarr(int *a,int i)
{
    for(int j=0;j<=i;j++)
    {
        cout<<a[j]<<", ";
    }
    cout<<endl;
}
void printpath(binary<int> *root ,int *a,int i)
{
    if(root==NULL){return;}
    a[i]=root->data;
    if(root->left==NULL && root->right==NULL)
    {
        printarr(a,i);
    }


        printpath(root->left,a,i+1);
        printpath(root->right,a,i+1);

}
void printpathtoleaf(binary<int> *root)
{
    if(root==NULL){return;}
    int *a=new int[10];
    printpath(root,a,0);
}
int main()
{
    binary<int> *root=takeinputofbinarylvlwise();
    //printbinary(root);
    cout<<"level wise"<<endl;
    printlevel(root);
    cout<<endl;
    /*cout<<"check bst"<<endl;
    cout<<isbst(root,INT_MAX,INT_MIN)<<endl;
    cout<<endl;
    cout<<"vertical level wise"<<endl;
    callprintvertical(root);
    cout<<"top view"<<endl;
    topviewprint(root);
    int n=0,k=0;
    cout<<"left view"<<endl;
    leftview(root,1,n);
    cout<<"right view"<<endl;
    rightview(root,1,k);
    cout<<"bottom view"<<endl;
    bottomviewprint(root);*/
    cout<<"left leaf sum"<<endl;
    cout<<sumleftleaf(root);
    cout<<endl;
    cout<<"node k from root"<<endl;
    printnodeatkdistance(root,2);
    cout<<endl;
    cout<<"node at k distance from target"<<endl;
    printnodeatkdistancefromgivennode(root,root->left,2);
    cout<<endl;
    cout<<"path to leaf node"<<endl;
    printpathtoleaf(root);
    return 0;
}
