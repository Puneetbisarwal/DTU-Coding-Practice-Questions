#include<bits/stdc++.h>
using namespace std;
int mincostpth(int **a,int r,int c,int h,int v)
{
    if(h>=r || v>=c)
    {
        return INT_MAX;
    }
    if(h==r-1 && v==c-1)
    {
        return a[h][v];
    }
    int ans1=mincostpth(a,r,c,h+1,v);
    int ans2=mincostpth(a,r,c,h,v+1);
    int ans3=mincostpth(a,r,c,h+1,v+1);
    return a[h][v]+min(ans1,min(ans2,ans3));
}
int mincostpathM(int **a,int m ,int n , int **out, int i ,int j)
{
    if(i>=m || j >=n)
    {
        return INT_MAX;
    }
    if(i==m-1 && j==n-1)
    {
        out[m-1][n-1]=a[i][j];
        return out[i][j];
    }
    if(out[i][j]!=-1)
    {
        return out[i][j];
    }
    int ans1=mincostpathM(a,m,n,out,i,j+1);
    int ans2=mincostpathM(a,m,n,out,i+1,j+1);
    int ans3=mincostpathM(a,m,n,out,i+1,j);
    out[i][j]= a[i][j]+min(ans1,min(ans2,ans3));
    return out[i][j];
}
int mincostpathDp(int **a,int m,int n)
{
    int out[m][n];
    out[0][0]=a[0][0];
    for(int i=1;i<m;i++)
    {
        out[i][0]=out[i-1][0]+a[i][0];
    }
    for(int i=1;i<n;i++)
    {
        out[0][i]=out[0][i-1]+a[0][i];
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            out[i][j]=a[i][j]+min(out[i-1][j],min(out[i][j-1],out[i-1][j-1]));
        }
    }
    return out[m-1][n-1];
}
int mincostpathM(int **a,int m ,int n)
{
    int **out=new int*[m];
    for(int i=0;i<n;i++)
    {
        out[i]=new int[n];
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            out[i][j]=-1;
        }
    }
    return mincostpathM(a,m,n,out,0,0);
}
int mincostpath(int **a,int row ,int col)
{
    int h=0,v=0;
    return mincostpth(a,row,col,h,v);
}
int main()
{
    int n,m;
    cout<<"Enter no of rows and col "<<endl;
    cin>>m>>n;
    int **a=new int*[m];
    for(int i=0;i<m;i++)
    {
        a[i]=new int[n];
    }
    for(int i=0;i<m;i++){for(int j=0;j<n;j++){cin>>a[i][j];}}
    cout<<mincostpath(a,m,n)<<endl;
   cout<<mincostpathM(a,m,n)<<endl;
   cout<<mincostpathDp(a,m,n);
    return 0;
}
