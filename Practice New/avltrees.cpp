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
class binaryAvl
{
public:
    int data;
    int height;
    binaryAvl *left;
    binaryAvl *right;
    binaryAvl(int data)
    {
        this->data=data;
        height=1;
        left=NULL;
        right=NULL;
    }
};
class BST
{
    binary *root;
    public:
    binary *insert(int data ,binary *root)
    {
        if(root==NULL)
        {
            binary *root=new binary(data);
            return root;
        }
        if(root->data>data)
        {
            root->left=insert(data,root->left);
        }
        else
        {
            root->right=insert(data,root->right);
        }
        return root;
    }
    void insert(int data)
    {
        root=insert(data,root);
    }
    binary *del(int data ,binary *root)
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->data>data)
        {
            root->left=del(data,root->left);
            return root;
        }
        else if(root->data<data)
        {
            root->right=del(data,root->right);
            return root;
        }
        else
        {
            if(root->left==NULL && root->right==NULL)
            {
                return NULL;
            }
            else if(root->left==NULL)
            {
                return root->right;
            }
            else if(root->right==NULL)
            {
                return root->left;
            }
            else
            {
                binary *min=root->right;
                while(min->left!=NULL)
                {
                    min=min->left;
                }
                root->data=min->data;
                root->right=del(min->data,root->right);
                return root;
            }
        }
    }
    void del(int data)
    {
        root=del(data,root);
    }
    void print(binary *root)
    {
        if(root==NULL)
        {
            return;
        }
        cout<<root->data<<" ";
        print(root->right);
        print(root->left);
    }
    void print()
    {
        print(root);
    }
};
class avl
{
private:
    binaryAvl *leftrotate(binaryAvl *root)
    {
        binaryAvl *x=root->right;
        binaryAvl *t2=x->left;
        x->left=root;
        root->right=t2;
        root->height=max(height(root->left),height(root->right))+1;
        x->height=max(height(x->left),height(x->right))+1;
        return x;
    }
    binaryAvl *rightrotate(binaryAvl *root)
    {
        binaryAvl *x=root->left;
        binaryAvl *t2=x->right;
        x->right=root;
        root->left=t2;
        root->height=max(height(root->left),height(root->right))+1;
        x->height=max(height(x->left),height(x->right))+1;
        return x;
    }
    int height(binaryAvl *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        return root->height;
    }
    int balfac(binaryAvl *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        return height(root->left)-height(root->right);
    }
    public:
    binaryAvl *root;
    avl()
    {
        root=NULL;
    }

    binaryAvl *insert(binaryAvl *root ,int data)
    {
        if(root==NULL)
        {
            binaryAvl *root=new binaryAvl(data);
            return root;
        }
        if(root->data>data)
        {
            root->left=insert(root->left,data);
        }
        else
        {
            root->right=insert(root->right,data);
        }
        root->height=1+max(height(root->left),height(root->right));
        int bal=balfac(root);
        if(bal>1 && root->left->data>data)
        {
            return rightrotate(root);
        }
        if(bal>1 && root->left->data<data)
        {
            root->left=leftrotate(root->left);
            return rightrotate(root);
        }
        if(bal<-1 && root->data<data)
        {
            return leftrotate(root);
        }
        if(bal<-1 && root->data>data)
        {
            root->right=rightrotate(root->right);
            return leftrotate(root);
        }
        return root;
    }
    void insert(int data)
    {
        root=insert(root,data);

    }
    binaryAvl *del(binaryAvl *root,int data)
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->data>data)
        {
            root->left=del(root->left,data);
        }
        else if(root->data<data)
        {
            root->right=del(root->right,data);
        }
        else
        {
            if(root->left==NULL || root->right==NULL)
            {
                binaryAvl *temp=root->left?root->left:root->right;
                if(temp==NULL)
                {
                    temp=root;
                    root=NULL;
                }
                else
                {
                    root=temp;
                }
                free(temp);
            }
            else
            {
                binaryAvl *min=root->right;
                while(min->left!=NULL)
                {
                    min=min->left;
                }
                root->data=min->data;
                root->right=del(root->right,min->data);
            }
        }
        if(root==NULL)
        {
            return NULL;
        }
        root->height=1+max(height(root->left),height(root->right));
        int bal=balfac(root);
        if(bal>1 && balfac(root->left)>=0)
        {
            return rightrotate(root);
        }
        if(bal>1 && balfac(root->left)<0)
        {
            root->left=leftrotate(root->left);
            return rightrotate(root);
        }
        if(bal<-1 && balfac(root->right)<=0)
        {
            return leftrotate(root);
        }
        if(bal<-1 && balfac(root->right)>0)
        {
            root->right=rightrotate(root->right);
            return leftrotate(root);
        }
        return root;
    }
    void del(int data)
    {
        root=del(root,data);
    }
    void print(binaryAvl *root)
    {
        if(root==NULL)
        {
            return;
        }
        cout<<root->data<<" " ;
        print(root->left);
        print(root->right);
    }
    void print()
    {
        print(root);
    }
};
int main()
{
    int n;
    avl *root=new avl();
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        root->insert(a[i]);
    }
    root->del(5);
    root->del(2);
    root->print();
    return 0;
}
