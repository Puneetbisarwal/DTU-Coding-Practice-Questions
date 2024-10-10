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
class BST
{
	binary *root;
	public:
	binary *insert(binary *root ,int data)
	{
		if(root==NULL)
		{
			binary *root=new binary(data);
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
		return root;
	}
	void insert(int data)
	{
		root=insert(root,data);
	}
	binary *delinbst(binary *root ,int data)
	{
		if(root==NULL)
		{
			return NULL;
		}
		if(root->data>data)
		{
			root->left=delinbst(root->left,data);
			return root;
		}
		else if(root->data<data)
		{
			root->right=delinbst(root->right,data);
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
				root->right=delinbst(root->right,min->data);
				return root;
			}
		}
	}
	void delinbst(int data)
	{
		root=delinbst(root,data);
	}
	void printpre(binary *root)
	{
		if(root==NULL)
		{
			return;
		}
		cout<<root->data<<" ";
		printpre(root->left);
		printpre(root->right);
	}
	void printpre()
	{
		printpre(root);
	}
};
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		BST *binarysearchtree=new BST();
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			binarysearchtree->insert(a[i]);
		}
		int k;
		cin>>k;
		int d[k];
		for(int i=0;i<k;i++)
		{
			cin>>d[i];
		}
		for(int i=0;i<k;i++)
		{
			binarysearchtree->delinbst(d[i]);
		}
		binarysearchtree->printpre();
		cout<<endl;
	}
	return 0;
}
