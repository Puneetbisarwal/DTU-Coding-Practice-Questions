#include<bits/stdc++.h>
using namespace std;
int lcs(char *a,char *b,int s1,int s2,int i,int j)
{
    if(i>=s1 || j>=s2)
    {
        return 0;
    }
    if(a[i]==b[j])
    {
        return 1+lcs(a,b,s1,s2,i+1,j+1);
    }
    else
    {
        return max(lcs(a,b,s1,s2,i+1,j),lcs(a,b,s1,s2,i,j+1));
    }
}
int lcsM(char *a, char *b,int s1,int s2,int i,int j,int **out)
{
    if(i>=s1 || j>=s2)
    {
        return 0;
    }
    if(out[i][j]!=-1)
    {
        return out[i][j];
    }
     if(a[i]==b[j])
    {
        out[i][j]=1+lcsM(a,b,s1,s2,i+1,j+1,out);
    }
    else
    {
    int a1=lcsM(a,b,s1,s2,i+1,j,out);
    int a2=lcsM(a,b,s1,s2,i,j+1,out);
    out[i][j]=max(a1,a2);
    }
    return out[i][j];
}
int lcsM(char *a,char *b,int s1,int s2)
{
    int **out=new int*[s1+1];
    for(int i=0;i<=s1;i++)
    {
        out[i]=new int[s2];
    }
    for(int i=0;i<=s1;i++)
    {
        for(int j=0;j<=s2;j++)
        {
            out[i][j]=-1;
        }
    }
    return lcsM(a,b,s1,s2,0,0,out);
}
int lcsDp(char *a,char *b,int s1,int s2)
{
    int out[s1+1][s2+1];
    for(int i=0;i<=s1;i++)
    {
        for(int j=0;j<=s2;j++)
        {
            if(i==0||j==0)
            {
                out[i][j]=0;
            }
            else if(a[i-1]==b[j-1])
            {
                out[i][j]=1+out[i-1][j-1];
            }
            else
            {
                out[i][j]=max(out[i][j-1],out[i-1][j]);
            }
            }
    }

    return out[s1][s2];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,n;
    cin>>m>>n;
    char a[m],b[n];
    cin>>a>>b;
    cout<<lcs(a,b,m,n,0,0)<<endl;
    cout<<lcsM(a,b,m,n)<<endl;
    cout<<lcsDp(a,b,m,n);
    return 0;
}
