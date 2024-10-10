#include<bits/stdc++.h>
using namespace std;
class tree
{
    public:
    int data;
    vector<tree*> v;
    tree(int data)
    {
        this->data=data;
    }
};
tree* input()
{
    int data;
    cout<<"Enter node data "<<endl;
    cin>>data;
    tree *root=new tree(data);
    cout<<"Enter no. of children of "<<data<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        tree *child=input();
        root->v.push_back(child);
    }
    return root;
}
void printtree(tree *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" : ";
    for(int i=0;i<root->v.size();i++)
    {
        cout<<root->v[i]->data<<", ";
    }
    cout<<endl;
    for(int i=0;i<root->v.size();i++)
    {
        tree *child=root->v[i];
        printtree(child);
    }
}
void printlevelwisetree(tree *root)
{
    if(root==NULL)
    {
        return;
    }
    queue<tree*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        tree *curr=q.front();
        if(curr==NULL)
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
                break;
            }
        }
        cout<<curr->data<<" ";
        q.pop();
        for(int i=0;i<curr->v.size();i++)
        {
            q.push(curr->v[i]);
        }
    }
}
tree* inputlevel()
{
    cout<<"Enter root data"<<endl;
    int data;
    cin>>data;
    tree *root=new tree(data);
    queue<tree*> q;
    q.push(root);
    int n,ch;
    while(!q.empty())
    {
        tree *curr=q.front();
        cout<<"Enter no. of child of "<<curr->data<<endl;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cout<<"Enter "<<i+1<<" child of "<<curr->data<<endl;
            cin>>ch;
            tree *child=new tree(ch);
            curr->v.push_back(child);
            q.push(child);
        }
        q.pop();
    }
    return root;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //tree *node=input();
    tree *node=inputlevel();
    //printtree(node);
    //cout<<endl;
    printlevelwisetree(node);
    return 0;
}
