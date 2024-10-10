#include <iostream>
#include<cmath>
using namespace std;
#include <queue>
#include <math.h>
// #include <cmath>
#include "Node.h"
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

/*this code is for converting tree to link list*/
node<int>* linklistbst(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        return NULL;
    }

    node<int> *t2=new node<int>(root->data);
    node<int>* ans1=linklistbst(root->left);
    node<int>* ans2=linklistbst(root->right);
    node<int>* temp=ans1;
    if(ans1!=NULL)
    {
        while(ans1->next!=NULL)
        {
            ans1=ans1->next;
        }
        ans1->next=t2;
        t2->next=ans2;
        return ans1;
    }

//    if(ans2!=NULL)
  //  {
        t2->next=ans2;
    //}
    return t2;
}
BinaryTreeNode<int>* takeInput() {
    int data;
    cout << "Enter data : ";
    cin >> data;
    if(data == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();
    root -> left = leftChild;
    root -> right = rightChild;
    return root;
}

BinaryTreeNode<int>* takeInputLevelWise() {
    int data;
    cout << "Enter root data : ";
    cin >> data;
    if(data == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        BinaryTreeNode<int>* current = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of "
            << current -> data << " : ";
        int leftData;
        cin >> leftData;
        if(leftData != -1) {
            BinaryTreeNode<int>* left = new BinaryTreeNode<int>(leftData);
            current -> left = left;
            pendingNodes.push(left);
        }
        cout << "Enter right child of "
            << current -> data << " : ";
        int rightData;
        cin >> rightData;
        if(rightData != -1) {
            BinaryTreeNode<int>* right = new BinaryTreeNode<int>(rightData);
            current -> right = right;
            pendingNodes.push(right);
        }
    }
    return root;

}
int sum(BinaryTreeNode<int> *root)
{
    if(root==NULL){return 0;}
    //int res=0;
    //res+=sum(root->left);
    //res+=sum(root->right);
    int ls=sum(root->left);
    int rs=sum(root->right);
    return ls+rs+root->data;
}
int height(BinaryTreeNode<int> *root) {
    // Base case
    if(root == NULL) {
        return 0;
    }

    int leftHeight = height(root -> left);
    int rightHeight = height(root -> right);
    return max(leftHeight, rightHeight) + 1;

}
bool findanode(BinaryTreeNode<int> *root,int ele)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==ele)
    {
        return true;
    }
    bool ans=findanode(root->left,ele);
    if(ans==true)
        return true;
    else
        {
        bool ans1=findanode(root->right,ele);
        return ans1;
        }
}

BinaryTreeNode<int>* mirrortree(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        return root;
    }
    BinaryTreeNode<int> *temp1;
    temp1=root->left;
    root->left=root->right;
    root->right=temp1;
    BinaryTreeNode<int> *ans1=mirrortree(root->left);
    BinaryTreeNode<int> *ans2=mirrortree(root->right);
    root->left=ans1;
    root->right=ans2;
    return root;
}
/*class diapair
{
    public:
    int diame;
    int height;
};
diapair diameterbetter(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        diapair ans;
        ans.diame=0;
        ans.height=0;
        return ans;
    }
    diapair left=diameterbetter(root->left);
    diapair right=diameterbetter(root->right);
    int d1=left.height+right.height+1;
    int d2=left.diame;
    int d3=right.diame;

    diapair ans1;
    ans1.diame=max(d1,max(d2,d3));
    ans1.height=max(left.height,right.height)+1;
    return ans1;
}*/

class dia
{
    public:
    int h;
    int d;
};
dia diabetter(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        dia ans;
        ans.h=0;
        ans.d=0;
        return ans;
    }
    dia left=diabetter(root->left);
    dia right=diabetter(root->right);

    int res = left.h + right.h + 1;
    int ld=left.d;
    int rd=right.d;

    dia ans1;
    {

        ans1.d=max(res,max(ld,rd));
        ans1.h=max(left.h,right.h)+1;

        return ans1;
    }

}

int diameter(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int d1=height(root->left)+height(root->right)+1;
    int d2=diameter(root->left);
    int d3=diameter(root->left);
    return max(d1,max(d2,d3));
}
void print(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<endl;
    print(root->left);
    print(root->right);
}
bool searchbinarysearchtree(BinaryTreeNode<int> *root,int ele)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==ele)
    {
        return true;
    }
    if(root->data > ele)
    {
        bool ans1=searchbinarysearchtree(root->left,ele);
        return ans1;
    }
    else
    {
        bool ans2=searchbinarysearchtree(root->right,ele);
        return ans2;
    }
}
void printbstrange(BinaryTreeNode<int> *root,int k1,int k2)
{
    if(root==NULL)
    {
        return;
    }
    if(k2 < root->data)
    {
        printbstrange(root->left,k1,k2);
    }
    if(k1 > root->data)
    {
        printbstrange(root->right,k1,k2);
    }
    if(root->data >= k1 && root->data <= k2)
    {
        cout<<root->data<<endl;
        printbstrange(root->left,k1,k2);
        printbstrange(root->right,k1,k2);
    }
}
void printll(node<int> *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
}
// 1 2 3 4 5 6 -1 7 -1 -1 -1 -1 -1 -1 -1
int main() {
    BinaryTreeNode<int>* root=takeInputLevelWise();
    print(root);
    cout<<sum(root);
    //BinaryTreeNode<int>* root = takeInputLevelWise();
    //int n;
    //print(root);
    //cout<<"enter node to search"<<endl;
    //cin>>n;
    //bool ans=findanode(root,n);
    //if(ans==true)
    //cout<<"true"<<endl;
    //else
        //cout<<"false"<<endl;
        //cout<<"mirror";
        //BinaryTreeNode<int> *ans3=mirrortree(root);
        //print(ans3);
        //diapair ans5=diameterbetter(root);
        //cout<<ans5.diame<<endl;
        //bool ans=searchbinarysearchtree(root,3);
        //cout<<"search"<<ans<<endl;
        //printbstrange(root,5,20);
        //node<int> *ans=linklistbst(root);
        //printll(ans);
}
