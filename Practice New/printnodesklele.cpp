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
binary* createtree(int *pre ,int *ino ,int s, int e)
{
	static int si=0;
	if(s>=e)
	{
		return NULL;
	}
	int j;
	for(int i=s;i<e;i++)
	{
		if(pre[si]==ino[i])
		{
			j=i;
			break;
		}
	}
	binary *root=new binary(pre[si]);
	si++;
	root->left=createtree(pre,ino,s,j);
	root->right=createtree(pre,ino,j+1,e);
	return root;
}
void printkdistanceNodeDown(binary *root ,int k)
{
	if(root==NULL || k<0)
	{
		return;
	}
	if(k==0)
	{
		cout<<root->data<<" ";
		return;
	}
	printkdistanceNodeDown(root->left,k-1);
	printkdistanceNodeDown(root->right,k-1);
}
/*int printnodeatkdistance(binary *root ,binary* target ,int k)
{
	if(root==NULL)
	{
		return -1;
	}
	if(root==target)
	{
		printnode(root,k);
		return 0;
	}
	int ld=printnodeatkdistance(root->left,target,k);
	if(ld!=-1)
	{
		if(ld+1==k)
		{
			cout<<root->data<<" ";
		}
		else
		{
			printnodeatkdistance(root->right,target,k-ld-2);
		}
		return ld+1;
	}
	int rd=printnodeatkdistance(root->right,target,k);
	if(rd!=-1)
	{
		if(rd+1==k)
		{
			cout<<root->data<<" ";
		}
		else
		{
			printnodeatkdistance(root->left,target,k-rd-2);
		}
		return rd+1;
	}
	return -1;
}*/
int printkdistanceNode(binary* root, binary* target , int k)
{
    // Base Case 1: If tree is empty, return -1
    if (root == NULL) return -1;

    // If target is same as root.  Use the downward function
    // to print all nodes at distance k in subtree rooted with
    // target or root
    if (root == target)
    {
        printkdistanceNodeDown(root, k);
        return 0;
    }

    // Recur for left subtree
    int dl = printkdistanceNode(root->left, target, k);

    // Check if target node was found in left subtree
    if (dl != -1)
    {
         // If root is at distance k from target, print root
         // Note that dl is Distance of root's left child from target
         if (dl + 1 == k)
            cout << root->data << endl;

         // Else go to right subtree and print all k-dl-2 distant nodes
         // Note that the right child is 2 edges away from left child
         else
            printkdistanceNodeDown(root->right, k-dl-2);

         // Add 1 to the distance and return value for parent calls
         return 1 + dl;
    }

    // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE
    // Note that we reach here only when node was not found in left subtree
    int dr = printkdistanceNode(root->right, target, k);
    if (dr != -1)
    {
         if (dr + 1 == k)
            cout << root->data << endl;
         else
            printkdistanceNodeDown(root->left, k-dr-2);
         return 1 + dr;
    }

    // If target was neither present in left nor in right subtree
    return -1;
}
int main() {
	/*int n;
	cin>>n;
	int pre[n],ino[n];
	for(int i=0;i<n;i++)
	{
		cin>>pre[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>ino[i];
	}*/
	//binary *root=createtree(pre,ino,0,n);

	binary *root=new binary(60);
	root->left=new binary(65);
	root->right=new binary(70);
	root->left->left=new binary(50);
	int t;
	cin>>t;

	while(t--)
	{
		//int n,k;
		//cin>>n>>k;
		binary *target=root->left;
		printkdistanceNode(root,target,2);

		cout<<endl;
	}
	return 0;
}
