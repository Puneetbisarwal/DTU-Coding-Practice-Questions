#include<bits/stdc++.h>
using namespace std;
int editdistance(string s1,string s2)
{
    if(s1.length()==0)
    {
        return s2.length();
    }
    if(s2.length()==0)
    {
        return s1.length();
    }
    if(s1[0]==s2[0])
    {
        return editdistance(s1.substr(1),s2.substr(1));
    }
    else
    {
        int a1=editdistance(s1,s2.substr(1));
        int a2=editdistance(s1.substr(1),s2);
        int a3=editdistance(s1.substr(1),s2.substr(1));
        return 1+min(a1,min(a2,a3));
    }
}
int editdistanceM(string s1 ,string s2 ,int **storage)
{
    int m=s1.length();
    int n=s2.length();
    if(storage[m][n]!=-1)
    {
        return storage[m][n];
    }
    if(m==0)
    {
        storage[m][n]=n;
        return storage[m][n];
    }
    if(n==0)
    {
        storage[m][n]=m;
        return storage[m][n];
    }
    if(s1[0]==s2[0])
    {
        storage[m][n]=editdistanceM(s1.substr(1),s2.substr(1),storage);
    }
    else
    {
        int a1=editdistanceM(s1.substr(1),s2,storage);
        int a2=editdistanceM(s1,s2.substr(1),storage);
        int a3=editdistanceM(s1.substr(1),s2.substr(1),storage);
        storage[m][n]=1+min(a1,min(a2,a3));
    }
    return storage[m][n];
}
int editdistanceM(string s1 , string s2 )
{
    int m=s1.length();
    int n=s2.length();
    int **storage=new int*[m+1];
    for(int i=0;i<=m;i++)
    {
        storage[i]=new int[n+1];
        for(int j=0;j<=n;j++)
        {
            storage[i][j]=-1;
        }
    }
    return editdistanceM(s1,s2,storage);
}
int editdistanceDp(string s1 , string s2)
{
    int m=s1.length();
    int n=s2.length();
    int storage[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        storage[i][0]=i;
    }
    for(int i=0;i<=n;i++)
    {
        storage[0][i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                storage[i][j]=storage[i-1][j-1];
            }
            else
            {
                storage[i][j]=1+min(storage[i][j-1],min(storage[i-1][j],storage[i-1][j-1]));
            }
        }
    }
    return storage[m][n];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1,s2;
    cin>>s1>>s2;
    cout<<editdistanceDp(s1,s2)<<endl;
    cout<<editdistanceM(s1,s2)<<endl;
    cout<<editdistance(s1,s2)<<endl;
    return 0;
}
