#include<bits/stdc++.h>
using namespace std;
void printmatrix(int **a,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void dummymatrix(int **a,int row,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            a[i][j]=a[i][j-1]+a[i][j];
        }
    }
    for(int i=1;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            a[i][j]=a[i-1][j]+a[i][j];
        }
    }
}
void matrixquerysumproblem(vector<pair<int ,int>> & q1 , vector<pair<int,int>> &q2 ,vector<int> &out,int **a,int row,int col)
{
    for(auto i=q1.begin(),j=q2.begin();i!=q1.end(),j!=q2.end();i++,j++)
    {
        out.push_back(a[j->first-1][j->second-1]-a[i->first-2][j->second-1]-a[j->first-1][i->second-2]+a[i->first-2][i->second-2]);
    }
}
void printmatrixquesrysumproblem(vector<int> &v)
{
    for(auto i=v.begin();i!=v.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}
void matrixquerysumprobleminputquery()
{

    cout<<endl;
    cout<<"Enter row and col of matrix "<<endl;
    int row,col;
    int **a=new int*[row];
    for(int i=0;i<row;i++)
    {
        a[i]=new int[col];
    }
    cout<<"Enter elements of matix"<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>a[i][j];
        }
    }
    printmatrix(a,row,col);
    cout<<endl;
    cout<<"Enter no. of queries"<<endl;
    int n;
    cin>>n;
    vector<pair<int,int>> q1(5);
    vector<pair<int,int>> q2(5);
    for(int i=0;i<n;i++)
    {
        cout<<" Enter "<<i+1 << "query's first co-ordinate"<<endl;
        int tl1,tl2;
        cin>>tl1>>tl2;
        q1.push_back(make_pair(tl1,tl2));
        cout<<" Enter "<< i+1 << "query's second co-ordinte"<<endl;
        int br1,br2;
        cin>>br1>>br2;
        q2.push_back(make_pair(br1,br2));
    }
    vector<int> v(5);
    cout<<"Print dummy matrix"<< endl;
    dummymatrix(a,row,col);
    printmatrix(a,row,col);
    cout<<endl;
    matrixquerysumproblem(q1,q2,v,a,row,col);
    printmatrixquesrysumproblem(v);
}
int main()
{
    matrixquerysumprobleminputquery();
    return 0;
}
