#include<bits/stdc++.h>
using namespace std;
class tree
{
	public:
	int data;
	int noofchild;
	vector<tree*> *v;
	tree(int data ,int noofchild)
	{
		this->data=data;
		this->noofchild=noofchild;
		vector<tree*> *v=new vector<tree*>(noofchild);
		for(int i=0;i<noofchild;i++)
		{
			v->at(i)=NULL;
		}
	}
};
tree* inputtree()
{
	int data;
	cin>>data;
	int noofchild;
	cin>>noofchild;
	tree *root=new tree(data,noofchild);
	for(int i=0;i<noofchild;++i)
	{
		tree *child=inputtree();
		root->v->push_back(child);
	}
	return root;
}
int sumatklevel(tree *root ,int k)
{
	if(root==NULL)
	{
		return 0;
	}
	if(k==0)
	{
		return root->data;
	}
	int ans=0;
	for(int i=0;i<root->noofchild;i++)
	{
		ans=ans+sumatklevel(root->v->at(i),k-1);
	}
	return ans;
}
void print(tree *root)
{

    if(root==NULL)
    {

        return ;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->noofchild;++i)
    {
        print(root->v->at(i));
    }
}
int main() {
	tree *root=inputtree();
	print(root);
	int k;
	cin>>k;
	//int sum=sumatklevel(root,k);
	//cout<<sum;
	return 0;
}
