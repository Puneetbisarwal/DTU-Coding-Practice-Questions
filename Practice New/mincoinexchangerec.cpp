#include<bits/stdc++.h>
using namespace std;
int minco(int *a,int val,int n)
{
    if(val==0){return 0;}
    int res=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=val)
        {
            int sub=minco(a,val-a[i],n);
            if(sub!=INT_MAX && sub+1<res)
            {
                res=sub+1;
            }
        }
    }
    return res;
}
int mincoinop(int *a,int val,int n)
{
    int dp[val+1];
    dp[0]=0;
    for(int i=1;i<=val;i++)
    {
        dp[i]=INT_MAX;
    }
    for(int i=1;i<=val;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]<=i)
            {
                int sub=dp[i-a[j]];
                if(sub!=INT_MAX && sub+1<dp[i])
                {
                    dp[i]=sub+1;
                }
            }
        }
    }
    return dp[val];
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int b=mincoinop(a,11,n);
    if(b==INT_MAX)
    {
        cout<<"no sol";
    }
    else
    {
        cout<<b;
    }
    return 0;
}
