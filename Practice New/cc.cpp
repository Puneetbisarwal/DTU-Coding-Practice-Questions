#include<bits/stdc++.h>
using namespace std;
template<typename T>
class BinaryTreeNode
{
    public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *po, int *in, int s, int e)
{
    static int si=e-1;
    if(s>e)
    {
        return NULL;
    }
    int j=-1;
    for(int i=s ; i <e ;i++)
    {
        if(po[si]==in[i])
        {
            j=i;
            break;
        }
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(po[si]);
    si--;
    root->right=getTreeFromPostorderAndInorder(po,in,j+1,e);
    root->left=getTreeFromPostorderAndInorder(po,in,s,j);

}
BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
    return getTreeFromPostorderAndInorder(postorder,inorder,0,inLength);

}
void printlevel(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    q.push(NULL);
    while(!q.empty())
    {
        BinaryTreeNode<int> *current=q.front();
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
int main()
{
    int n;
    cin>>n;
    int po[n],ino[n];
    for(int i=0;i<n;i++)
    {
        cin>>po[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>ino[i];
    }
    BinaryTreeNode<int> *root=getTreeFromPostorderAndInorder(po,n,ino,n);
    printlevel(root);
    return 0;
}
